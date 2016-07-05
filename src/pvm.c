#include <stdio.h>
#include <stdlib.h>
#include <op_codes.h>

typedef void (*fcnptr)(int, int);
int* data_store;
int* code_store;
int registers[3];
int instruction_pointer;

//Moving data stored in location E to location D
void mov_op(int D, int E){
	data_store[D] = data_store[E];
}

//Putting data value N in location D
void mvi_op(int D, int N){
	data_store[D] = N;
}

//Moving data stored in location whos address is saved in E into location D
void mif_op(int D, int E){
	data_store[D] = data_store[data_store[E]];
}

//Moving data stored in location E to location whos address is saved in D
void mit_op(int D, int E){
	data_store[data_store[D]] = data_store[E]; 
}

//Putting value N into register R
void lri_op(int R, int N){
	registers[R] = N;
}

//Putting value store in location D into register R
void ldr_op(int R, int D){
	registers[R] = data_store[D];
}

//Putting value store in register R into loction D
void str_op(int D, int R){
	data_store[D] = registers[R];
}

//Putting value store in register S into register R
void mvr_op(int R, int S){
	registers[R] = registers[S];
}

//Saving result of values saved in D and E into D
void add_op(int D, int E){
	data_store[D] += data_store[E];
}

//Adding value of N to value saved in register R
void addri_op(int R, int N){
	registers[R] += N;
}

//Subtracting value store in E from value stored in D, saving result in D
void sub_op(int D, int E){
	data_store[D] -= data_store[E];
}

//Saving result of values store in D and E into D
void mul_op(int D, int E){
	data_store[D] *= data_store[E];
}

//Saving quotient of D and E into D
void div_op(int D, int E){
	data_store[D] /= data_store[E];
}

//Saving the OR of values stored in D and E into D
void or_op(int D, int E){
	data_store[D] = (data_store[D] || data_store[E]);
}

//Saving the AND of values stored in D and E into D
void and_op(int D, int E){
	data_store[D] &= data_store[E];
}

//Saving the NOT of values stored in D and E into D
void not_op(int D, int O){
	data_store[D] = !data_store[D];
}

//Branching to location A in codestore
void b_op(int A, int O){
	instruction_pointer = A;
}

//If value stored in D is 0, branch to location A in codestore
void beq_op(int A, int D){
	if(data_store[D] == 0) instruction_pointer = A;
	
}

//If value stored in D is not 0, branch to location A in codestore
void bne_op(int A, int D){
	if(data_store[D] != 0) instruction_pointer = A;

}

//If value stored in D is greater than 0, branch to location A in codestore
void bgt_op(int A, int D){
	if(data_store[D] > 0) instruction_pointer = A;
}

//If value stored in D is greater or equal to 0, 
//branch to location A in codestore
void bge_op(int A, int D){
	if(data_store[D] >= 0) instruction_pointer = A;
}

//If value stored in D is less than 0, branch to location A in codestore
void blt_op(int A, int D){
	if(data_store[D] < 0) instruction_pointer = A;
}

//If value store in D is less than or equal to 0,
//branch to location A in codestore
void ble_op(int A, int D){
	if(data_store[D] <= 0) instruction_pointer = A;
}


//Push value saved in location D on to the Stack
void pushd_op(int D, int O){
	registers[0] -= 1;
	data_store[registers[0]] = data_store[D];
}

//Push value saved in register R onto the Stack
void pushr_op(int R, int O){
	registers[0] -= 1;
	data_store[registers[0]] = registers[R];
}

//Push value N onto the Stack
void pushi_op(int N, int O){
	registers[0] -= 1;
	data_store[registers[0]] = N;
}

//Pop value off of the stack, save into location D
void popd_op(int D, int O){	
	data_store[D] = data_store[registers[0]];	
	registers[0] += 1;
}

//Pop value off of the stack, save into register R
void popr_op(int R, int O){
	registers[R] = data_store[registers[0]];
	registers[0] += 1;
}

//Print the integer value stored in location D
void puti_op(int D, int O){
	printf("%d", data_store[D]);
}

//Printing string starting at location D
void puts_op(int D, int O){
	//printing chars from data store until encountering null char
	while(data_store[D] != '\0'){
		printf("%c", (char)data_store[D]);
		D++;
	}
}

//Print new line
void line_op(int O, int OO){
	printf("\n");
}

//Get an integer value from the user
void geti_op(int D, int O){
	scanf("%d", &data_store[D]);
	// a new line char will be left in the input stream, this gets rid of it
	int ch;
	while ((ch=getchar()) != EOF && ch != '\n');
}

//Get a string from the user
void gets_op(int D, int O){
	char c = getchar();
	// saving chars to data store until user presses enter
	while(c != '\n'){
		data_store[D] = c;
		D++;
		c = getchar();
	}
	data_store[D] = '\0';
}

//Calling code saved at location A, saving instruction pointer for return
void call_op(int A, int O){
	pushi_op(instruction_pointer, 0);
	b_op(A, 0);
}

//Returning from a call, remove N items from the stack
void ret_op(int N, int O){
	instruction_pointer = data_store[registers[0]];		
	registers[0] += (N + 1);
}

//End execution
void stop_op(int O, int OO){
	printf("Exiting PVM\n");
	free(data_store);
	free(code_store);
	exit(0);
}

int main(int argc, char* argv[]){
	//setting the value of the stack pointer
	registers[0] = 500;	
	registers[1] = 500;
	FILE *fp;
	int size_cs, string_start, string_space, entry_point;
	int op_code, arg1, arg2;
	// putting all the function pointers into the array
	fcnptr instructions[e_num_of_ops];
	instructions[e_null] = NULL; instructions[e_mov_op] = mov_op; 
	instructions[e_mvi_op] = mvi_op; instructions[e_mif_op] = mif_op; 
	instructions[e_mit_op] = mit_op; instructions[e_lri_op] = lri_op;
	instructions[e_ldr_op] = ldr_op; instructions[e_str_op] = str_op; 
	instructions[e_mvr_op] = mvr_op; instructions[e_add_op] = add_op; 
	instructions[e_addri_op] = addri_op; instructions[e_sub_op] = sub_op;
	instructions[e_mul_op] = mul_op; instructions[e_div_op] = div_op; 
	instructions[e_or_op] = or_op; instructions[e_and_op] = and_op; 
	instructions[e_not_op] = not_op; instructions[e_b_op] = b_op;
	instructions[e_beq_op] = beq_op; instructions[e_bne_op] = bne_op; 
	instructions[e_bgt_op] = bgt_op; instructions[e_bge_op] = bge_op;
	instructions[e_blt_op] = blt_op; instructions[e_ble_op] = ble_op;
	instructions[e_pushd_op] = pushd_op; instructions[e_pushr_op] = pushr_op;
	instructions[e_pushi_op] = pushi_op; instructions[e_popd_op] = popd_op; 
	instructions[e_popr_op] = popr_op; instructions[e_puti_op] = puti_op;
	instructions[e_puts_op] = puts_op; instructions[e_line_op] = line_op; 
	instructions[e_geti_op] = geti_op; instructions[e_gets_op] = gets_op; 
	instructions[e_call_op] = call_op; instructions[e_ret_op] = ret_op;
	instructions[e_stop_op] = stop_op;
	
	//Checking if the file name was given as command line arg
	if(argc < 2){
		printf("Please Provide a File Name\n");
		exit(1);
	}
	else{
		printf("Starting PVM\n");
		fp = fopen(argv[1], "r");
	}
	//Check if the file exists and was able to be opened
	if(fp == NULL){
		printf("Could Not Open File\n");
		exit(1);	
	}

	//Read in header from pvm file
	fscanf(fp, "%d %d %d %d", &size_cs, &string_start, &string_space, &entry_point);	
	code_store = calloc(size_cs, sizeof(int));
	data_store = calloc((string_start + string_space), sizeof(int));
	// loading the code from the file into the code_store	
	int i = 0;
	while((i < size_cs) && (fscanf(fp, "%d %d %d", &op_code, &arg1, &arg2) == 3)){
		code_store[i++] = op_code;
		code_store[i++] = arg1;
		code_store[i++] = arg2;
			
	}
	//Read the strings into the Data Store
	int ascii_val;
	i = string_start;
	while(fscanf(fp, "%d", &ascii_val) != EOF){
		data_store[i] = ascii_val;
		i++;
	}	
	fclose(fp);
	instruction_pointer = entry_point;
	// Execution Cycle
	while(1){
		op_code = code_store[instruction_pointer];
		arg1 = code_store[instruction_pointer + 1];
		arg2 = code_store[instruction_pointer + 2];	
		instruction_pointer += 3;
		instructions[op_code](arg1, arg2);
	}
	return 0;
}
