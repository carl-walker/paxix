%{

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"

// Global Var declarations
static int param_ctr = 0;
static int local_ctr = 0;
char* proc_name;

// Values shared between flex, bison, and driver files
extern int* code_store;
extern int cs_pointer; 
extern int line_count;
extern int next_avail;
extern int string_space;
extern int entry_point;

char* mangle(char* proc, char* var);
void emit(int opcode, int arg1, int arg2);
void backpatch(int address, int opcode, int arg1, int arg2);
void yyerror(char *str);
int yylex();
%}

%token ID_TOKEN INT_TOKEN STRING_TOKEN CHAR_TOKEN NEWLINE_TOKEN WHITESPACE_TOKEN
%token AND_TOKEN ARRAY_TOKEN DO_TOKEN ELSE_TOKEN ENDO_TOKEN ENDIF_TOKEN
%token ENDPROC_TOKEN ENDWHILE_TOKEN IF_TOKEN LINE_TOKEN NOT_TOKEN OR_TOKEN
%token PROC_TOKEN READ_TOKEN READSTR_TOKEN RETVAL_TOKEN VAR_TOKEN
%token WHILE_TOKEN WRITESTR_TOKEN WRITE_TOKEN ADD_TOKEN SUBTRACT_TOKEN
%token MULT_TOKEN DIV_TOKEN EQUAL_TOKEN LT_TOKEN LTEQ_TOKEN GT_TOKEN
%token GTEQ_TOKEN HASH_TOKEN LPAREN_TOKEN RPAREN_TOKEN LBRACE_TOKEN
%token RBRACE_TOKEN COMMA_TOKEN SEMICOLON_TOKEN DOUBLEQUOTE_TOKEN 
%token SINGLEQUOTE_TOKEN

%union{
	int ival;
	char* strval;
	struct symtab_entry_s* entryval;
}

%%

program: globals_list procedure_list;

globals_list: globals_list globals_decl | ;

globals_decl: global_var_decl | array_decl;

global_var_decl: VAR_TOKEN global_var_list SEMICOLON_TOKEN;

global_var_list: global_var_list COMMA_TOKEN ID_TOKEN 
		{
			if(lookup($<strval>3) == NULL){
				insert($<strval>3, "variable", 1, next_avail);
				next_avail += 1;
			}else{
				yyerror("Variable defined earlier in program");
			}	
		}
		| ID_TOKEN
		{
			if(lookup($<strval>1) == NULL){
				insert($<strval>1, "variable", 1, next_avail);
				next_avail += 1;
			}else{
				yyerror("Variable defined earlier in program");
			}
		};

array_decl: ARRAY_TOKEN array_list SEMICOLON_TOKEN;

array_list: array_list COMMA_TOKEN single_array | single_array;

single_array: 	INT_TOKEN ID_TOKEN
		{
			if(lookup($<strval>2) == NULL){
				insert($<strval>2, "array", $<ival>1, next_avail);
				next_avail += $<ival>1;
			}else{
				yyerror("Array identifier defined earlier in program");	
			}
		};

procedure_list: procedure_list procedure_decl | ;

procedure_decl: PROC_TOKEN ID_TOKEN
		{
			if(lookup($<strval>2) == NULL){
				// save newly read procedure name into global
				char* new_proc = malloc(sizeof($<strval>2 + 1));
				strcpy(new_proc, $<strval>2);
				proc_name = new_proc;
				param_ctr = 0;
				local_ctr = 0;
			}else{
				yyerror("Procedure name defined earlier in program");
			}

			// doing this so that main doesnt break
			if(!strcmp(proc_name, "main")){
				entry_point = cs_pointer;
			}
		} 
		LPAREN_TOKEN formal_parameters 
		{
			//cs_pointer may be the wrong thing here	
			insert($<strval>2, "procedure", param_ctr, cs_pointer);
			
			//start executing in main	
			if(!strcmp(proc_name, "main")){
			//	entry_point = cs_pointer;
			} 	
			// push current frame pointer value 
			// copy value of stack pointer to frame pointer
			emit(25, 1, 0);
			emit(8, 1, 0);
					
		}
		RPAREN_TOKEN locals_list
		{
			emit(10, 0, -local_ctr);
		} 
		statement_list 
		{ 
			/* Clearing stack frame
			 * 
			 * Deallocate stack pointer, inc by # of local vars
			 * Pop frame pointer into Register 1
			 * return instruction with parameter count as argument
			 */
			emit(10, 0, local_ctr);
			emit(28, 1, 0);
		}
		ENDPROC_TOKEN	
		{
		
			//emitting stop_op if at the end of main
			if(!strcmp(proc_name, "main")){
				emit(36, 0, 0);
			}else{
				//emit a return
				emit(35, param_ctr, 0);	
			}
		};


formal_parameters: formal_list | ;

formal_list: 	formal_list COMMA_TOKEN ID_TOKEN 
	     	{
			//Changed param_ctr++ to ++param_ctr
			char* mangled_param = mangle(proc_name, $<strval>3);
			insert(mangled_param, "parameter", 1, ++param_ctr);
		}
	     	| ID_TOKEN
		{
			char* mangled_param = mangle(proc_name, $<strval>1);
			insert(mangled_param, "parameter", 1, ++param_ctr);
		}; 

locals_list: locals_list local_decl | ;

local_decl: VAR_TOKEN local_var_list SEMICOLON_TOKEN;

local_var_list: local_var_list COMMA_TOKEN ID_TOKEN 
		{
			//changed local_ctr++ to ++local_ctr
			char* mangled_param = mangle(proc_name, $<strval>3);
			insert(mangled_param, "local_variable", 1, ++local_ctr);	
		}
		| ID_TOKEN
		{
			char* mangled_param = mangle(proc_name, $<strval>1);
			insert(mangled_param, "local_variable", 1, ++local_ctr);
		};

statement_list: statement_list statement SEMICOLON_TOKEN | ;

statement: assignment | conditional | loop | io | call | return_value;

assignment: variable EQUAL_TOKEN arithmetic_expression
	    {
		//popping variable address and value
		//moving value into variable address
	 	emit(27, 500, 0);
		emit(27, 501, 0);
		emit(4, 501, 500); 
	    };

conditional: IF_TOKEN boolean_expression
	     {
		
	     	emit(27, 500, 0); //pop top of stack
		$<ival>2 = cs_pointer; //save address for backpatching
		emit(999, 999, 999); // emit dummy instuction for backpatching
             }
             statement_list
	     {
	     	$<ival>4 = cs_pointer;
	        emit(999, 999, 999);
		//if boolean_expression is false, jump here
		backpatch($<ival>2, 18, cs_pointer, 500); 
	     }
	     else_clause
	     {
		//jump over the else if boolean_expression is true
             	backpatch($<ival>4, 17, cs_pointer, 0);
	     }
             ENDIF_TOKEN;

else_clause: ELSE_TOKEN statement_list | ;

loop: while_loop | do_loop;

while_loop: WHILE_TOKEN 
	    {
		//save start location of loop
	    	$<ival>1 = cs_pointer;
	    }
	    boolean_expression
	    {
		emit(27, 500, 0);
		$<ival>3 = cs_pointer;
		emit(999, 999, 999);	    
	    } 
	    statement_list
            {
		//if boolean_expression is false exit the loop
            	backpatch($<ival>3, 18, cs_pointer+3, 500);
		//if boolean_expression is true, keep looping
		emit(17, $<ival>1, 0);
            }
            ENDWHILE_TOKEN;

do_loop: DO_TOKEN
	 {
		//save beginning of loop
	 	$<ival>1 = cs_pointer;
	 } 
	 statement_list ENDO_TOKEN WHILE_TOKEN boolean_expression
	 {
	 	emit(27, 500, 0);
		//if boolean_expression is false exit the loop
		emit(18, cs_pointer+6, 500);
		//if boolean_expression is true keep looping
		emit(17, $<ival>1, 0);
	 };

io: read_statement | write_statement | line_statement;

call: ID_TOKEN LPAREN_TOKEN actual_parameters
      {
      	/* count paramters in actual_parameters and parameters list
	 * look up procedure in symtab and compare parameters with expected values
	 * emit a call instruction with the locaiton field fo symtab entry as arg
	 */
	struct symtab_entry_s* entry;
	entry = lookup($<strval>1);
	if(entry != NULL && !strcmp(entry->type, "procedure")){
		if($<ival>3 == entry->size){
			emit(34, entry->location, 0);
		}else{
			printf("%d %d\n", $<ival>3, entry->size);
			yyerror("Procedure called with wrong amount of params");
		}	
	}else{
		yyerror("Bad procedure call");
	}

		
	//emmiting call instruction
      	//emit(34, entry->location, 0);
      } RPAREN_TOKEN;

return_value: RETVAL_TOKEN arithmetic_expression
	      {
		 // pop top of stack into Register 2
		emit(28, 2, 0);
	      };

actual_parameters: parameter_list 
			{
				$<ival>$ = $<ival>1;
			}
			|
			{ 
				$<ival>$ = 0;
			} ;

parameter_list: parameter_list COMMA_TOKEN arithmetic_expression
		{
			$<ival>$ = $<ival>1 + 1;
		} 
		|arithmetic_expression
		{
			$<ival>$ = 1;
		};

quantity: variable
	  {
		//pushing variable address onto stack
		emit(27, 500, 0);
		emit(3, 500, 500);
		emit(24, 500, 0); 
	  } 
	  | INT_TOKEN 
	  {
	  	emit(26, $<ival>1, 0);
	  }
	  | call 
	  {
		// push the value in register 2 onto stack
		emit(25, 2, 0);
	  }
	  | CHAR_TOKEN
	  {
	  	emit(26, $<ival>1, 0);
	  };

variable: ID_TOKEN 
	  {

		/* 
		 * add (p-n+2) to frame pointer to get addres of parameter
		 * p is the param_ctr
		 * 
		 * addresses of local vars is done by finding the location relative to fp
		 * lv1 = (fp + 1)
		 */
			
		$<ival>$ = ID_TOKEN;
		int location;
		int offset;
		struct symtab_entry_s* entry;
		char* mangled_param = mangle(proc_name, $<strval>1);
		entry = lookup(mangled_param);
		//if mangled version in symtab
		if(entry != NULL){
			if(!strcmp(entry->type, "local_variable")){
		       		location = entry->location;
				emit(7, 500, 1);
				emit(2, 501, location);
				emit(11, 500, 501);
				emit(24, 500, 0);

			}else if(!strcmp(entry->type, "parameter")){
				//Looking up parameter passed into function
				offset = (param_ctr - entry->location + 2);
				emit(7, 500, 1);
				emit(2, 501, offset);
				emit(9, 500, 501);
				//emit(3, 500, 500);
				emit(24, 500, 0);
			}
				
                }else{
			//lookup unmagled for if variable
                        entry = lookup($<strval>1);
                        if(entry != NULL){
                               if(!strcmp(entry->type, "variable")){
					location = entry->location;
			       		emit(26, location, 0);
			       }
                        }

                }
		if(entry == NULL){
			yyerror("Attempt to use undeclared variable");
		}
		//printf("%s\n", $<strval>1);
		free($<strval>1);		
	  }
	  | ID_TOKEN	  
	  {
	  	//ARRAY REFERENCE
	 	int location;
		struct symtab_entry_s* entry;
		entry = lookup($<strval>1);
		if(entry != NULL){
                       if(!strcmp(entry->type, "array")){
		       		location = entry->location;
				//ARRAY BASE LOCATION PUSHED
				emit(26, location, 0);
			}
		}
       		if(entry == NULL){
			yyerror("Attempt to access undelcared array");
		}
	  }
	  LBRACE_TOKEN arithmetic_expression
	  {
		//POP the base address and offset
	 	emit(27, 501, 0);
		emit(27, 500, 0);
		//Add offset to base address
		emit(9, 500, 501);
		//push location+offset
		emit(24, 500, 0);
		
	  } RBRACE_TOKEN;

read_statement: READ_TOKEN LPAREN_TOKEN variable RPAREN_TOKEN
		{
				
			//the geti operation
			emit(27, 500, 0);
			emit(32, 501, 0);
			emit(4, 500, 501);
	
		}
		| READSTR_TOKEN LPAREN_TOKEN ID_TOKEN RPAREN_TOKEN
		{
		        int location;
                        struct symtab_entry_s* entry;
                        entry = lookup($<strval>3);
                        if(entry != NULL){
                               if(!strcmp(entry->type, "array")){
                                        location = entry->location;
                                        //Print string starting at location
                                        emit(33, location, 0);
                                }
                        }
                        if(entry == NULL){
                                yyerror("Attempt to access undelcared array");
                        }		
		};

write_statement: WRITE_TOKEN LPAREN_TOKEN arithmetic_expression RPAREN_TOKEN
		 {
		 	emit(27, 500, 0);
			emit(29, 500, 0);
		 }
		 | WRITESTR_TOKEN LPAREN_TOKEN STRING_TOKEN
		 {
			emit(30, (next_avail + string_space), 0);
			string_space += ($<ival>3 - 1);	 
		 } 
		 RPAREN_TOKEN
		 
		 | WRITESTR_TOKEN LPAREN_TOKEN ID_TOKEN 
		 {
 	
			int location;
                	struct symtab_entry_s* entry;
                	entry = lookup($<strval>3);
                	if(entry != NULL){
                	       if(!strcmp(entry->type, "array")){
                	                location = entry->location;
                	                //Print string starting at location
                	                emit(30, location, 0);
                	        }
                	}
                	if(entry == NULL){
                	        yyerror("Attempt to access undelcared array");
                	}
		
		 }
		 RPAREN_TOKEN;

line_statement: LINE_TOKEN
		{
			emit(31, 0, 0);
		};

arithmetic_expression: arithmetic_expression add_operator arithmetic_term
		       {
	       	       		emit(27, 501, 0);
				emit(27, 500, 0);
				if($<ival>2 == ADD_TOKEN){
					emit(9, 500, 501);
				}
				else if($<ival>2 == SUBTRACT_TOKEN){
					emit(11, 500, 501);
				}
				emit(24, 500, 0);
			
		       }
		       | arithmetic_term;

arithmetic_term: arithmetic_term mult_operator arithmetic_factor 
		 {
			emit(27, 501, 0);
			emit(27, 500, 0);
  			if($<ival>2 == MULT_TOKEN){
                                emit(12, 500, 501);
                        }
                        if($<ival>2 == DIV_TOKEN){
                                emit(13, 500, 501);
                        }
			emit(24, 500, 0);
		 }
		 | arithmetic_factor;

arithmetic_factor: quantity | LPAREN_TOKEN arithmetic_expression RPAREN_TOKEN;

add_operator: ADD_TOKEN 
	      {
		$<ival>$ = ADD_TOKEN;
	      }
	      | SUBTRACT_TOKEN
	      {
	      	$<ival>$ = SUBTRACT_TOKEN;
              };

mult_operator: MULT_TOKEN 
	       {
               	$<ival>$ = MULT_TOKEN;
	       }
               | DIV_TOKEN
	       {
               	$<ival>$ = DIV_TOKEN;
	       };

boolean_expression: boolean_expression OR_TOKEN boolean_term
		    {
			//pop vals into scratch
			//Or them, push back onto stack
		    	emit(27, 500, 0);
			emit(27, 501, 0);
			emit(14, 500, 501);
			emit(24, 500, 0);
		    }
		    | boolean_term;

boolean_term: 	boolean_term AND_TOKEN boolean_factor 
		{
			//pop vals into scratch
			//And them, push back onto stack
			emit(27, 500, 0);
			emit(27, 501, 0);
			emit(15, 500, 501);
			emit(24, 500, 0); 
		}
		| boolean_factor;

boolean_factor:	NOT_TOKEN boolean_atom 
		{
			//pop value
			//boolean Not, push back onto stack
			emit(27, 500, 0);
			emit(16, 500, 0);
			emit(24, 500, 0);
		}
		| boolean_atom;

boolean_atom: 	LPAREN_TOKEN arithmetic_expression relational_operator 
		arithmetic_expression RPAREN_TOKEN
		{
			emit(27, 501, 0);
			emit(27, 500, 0);
			//subract values, branch compares to 0 
			emit(11, 500, 501); 
			// if true, jump 3 lines
			emit($<ival>3, cs_pointer+9, 500); 
			emit(26, 0, 0); //push 0 for false
			emit(17, cs_pointer+6, 0); // jump 2 lines
			emit(26, 1, 0);	// push 1 for true
		}
		| LPAREN_TOKEN boolean_expression RPAREN_TOKEN;

relational_operator: 	EQUAL_TOKEN
			{
				//Using parse stack to pass up opcodes
				$<ival>$ = 18;
			} 
			| LT_TOKEN
			{
				$<ival>$ = 22;
			} 
			| LTEQ_TOKEN 
			{
				$<ival>$ = 23;
			}
			| GT_TOKEN
			{
				$<ival>$ = 20;
			} 
			| GTEQ_TOKEN
			{
				$<ival>$ = 21;
			} 
			| HASH_TOKEN
			{
				$<ival>$ = 19;
			};

%%

void yyerror(char *str){
	printf("%s\nLine: %d\n", str, line_count);
	exit(1);
}

void emit(int opcode, int arg1, int arg2){

	code_store[cs_pointer] = opcode;
	code_store[cs_pointer + 1] = arg1;
	code_store[cs_pointer + 2] = arg2;	
	cs_pointer += 3;

	//Resize code_store if it fills up	
	if((cs_pointer%300)==0){
		code_store = (int*) realloc(code_store,
				 	   ((300+cs_pointer)*sizeof(int)));
	}

}

void backpatch(int address, int opcode, int arg1, int arg2){
	code_store[address] = opcode;
	code_store[address + 1] = arg1;
	code_store[address + 2] = arg2;	
}

char* mangle(char* proc, char* var){
        int i = 0;
        int len = 0;

        while(*(var + len) != '\0'){
                len++;
        }
        len++;

        //find length of associated proc
        while(*(proc + i) != '\0'){
                i++;
        }
        i++;
        //determine size of mangled string and malloc it
        int mangled_len = (len + i);
        //printf("%d\n", mangled_len);
        char* mangled_param = calloc((mangled_len+1), sizeof(char));
        len = i = 0;
        // put the var name infront of the proc
        while(*(var + i) != '\0'){
                mangled_param[i] = *(var + i);
                i++;
        }
       // i++;
        mangled_param[i] = '@';
        i++;
        while(*(proc + len) != '\0'){
                mangled_param[i + len] = *(proc+len);
                len++;
        }
        return mangled_param;
}

