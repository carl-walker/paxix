#include <stdio.h>
#include <stdlib.h>

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
	fcnptr instructions[37];
	instructions[0] = NULL; instructions[1] = mov_op; 
	instructions[2] = mvi_op; instructions[3] = mif_op; 
	instructions[4] = mit_op; instructions[5] = lri_op;
	instructions[6] = ldr_op; instructions[7] = str_op; 
	instructions[8] = mvr_op; instructions[9] = add_op; 
	instructions[10] = addri_op; instructions[11] = sub_op;
	instructions[12] = mul_op; instructions[13] = div_op; 
	instructions[14] = or_op; instructions[15] = and_op; 
	instructions[16] = not_op; instructions[17] = b_op;
	instructions[18] = beq_op; instructions[19] = bne_op; 
	instructions[20] = bgt_op; instructions[21] = bge_op;
	instructions[22] = blt_op; instructions[23] = ble_op;
	instructions[24] = pushd_op; instructions[25] = pushr_op;
	instructions[26] = pushi_op; instructions[27] = popd_op; 
	instructions[28] = popr_op; instructions[29] = puti_op;
	instructions[30] = puts_op; instructions[31] = line_op; 
	instructions[32] = geti_op; instructions[33] = gets_op; 
	instructions[34] = call_op; instructions[35] = ret_op;
	instructions[36] = stop_op;
	
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
