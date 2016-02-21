%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_list.h"
#include "paxi_parser.tab.h"

int line_count = 1;
int input_integer;
%}

%%

"and"		return AND_TOKEN;
"array"		return ARRAY_TOKEN;
"do"		return DO_TOKEN;
"else"		return ELSE_TOKEN;
"endo"		return ENDO_TOKEN;
"endif"		return ENDIF_TOKEN;
"endproc"	return ENDPROC_TOKEN;
"endwhile"	return ENDWHILE_TOKEN;
"if"		return IF_TOKEN;
"line"		return LINE_TOKEN;
"not"		return NOT_TOKEN;
"or"		return OR_TOKEN;
"proc"		return PROC_TOKEN;
"read"		return READ_TOKEN;
"readstr" 	return READSTR_TOKEN;
"retval"	return RETVAL_TOKEN;
"var"		return VAR_TOKEN;
"while" 	return WHILE_TOKEN;
"writestr"	return WRITESTR_TOKEN;
"write"		return WRITE_TOKEN;
\+		return ADD_TOKEN;
\- 		return SUBTRACT_TOKEN;
\*		return MULT_TOKEN;
\/		return DIV_TOKEN;
=		return EQUAL_TOKEN;
\<		return LT_TOKEN;
\<=		return LTEQ_TOKEN;
>=		return GTEQ_TOKEN;
>		return GT_TOKEN;
#		return HASH_TOKEN;
\(		return LPAREN_TOKEN;
\)		return RPAREN_TOKEN;
\[		return LBRACE_TOKEN;
\]		return RBRACE_TOKEN;
,		return COMMA_TOKEN;
;		return SEMICOLON_TOKEN;
\"		return DOUBLEQUOTE_TOKEN;
\'		return SINGLEQUOTE_TOKEN;

[a-zA-Z_][a-zA-Z0-9_]*	{
			yylval.strval = malloc(sizeof(yytext+1));
			return ID_TOKEN;
			}

\-?[0-9]+ 	{
			input_integer = atoi(yytext);
			yylval.ival = input_integer;
			return INT_TOKEN;
		}

\".*\"		{
			//TODO: Refactor
			/*
				Get yytext length
				set yylval.ival = length
				create a new string of that length
					
			*/

			int i, len = 0;
			while(*(yytext + len) != '\0'){
				len++;
			}
			yylval.ival = len;
			//creating new string because yytext gets rewritten to
			char* input_string = malloc(sizeof(char)*len);
			strcpy(input_string, yytext);
			//removing first quote by advancing pointer	
			input_string++;
			//removing second quote by replacing " with \0
			*(input_string + (len-2)) = '\0';
			add_string(input_string);
			return STRING_TOKEN;
		}

\'.\' 		{
			yylval.ival = yytext[1];
			return CHAR_TOKEN;
		} 

\n 	line_count++;

\/\/.*		

[ \t] 		

.		{
			printf("Syntax Error: line %d\n", line_count);
			exit(1);
		}

%%

int yywrap(){
	return 1;
}
