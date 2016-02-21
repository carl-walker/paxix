#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_list.h"
#include "paxi_parser.tab.h"

extern FILE* yyin;
FILE* output;
extern char* yytext;
extern string_list_t* string_list;
extern struct hash_table_s* hash_table;
int* code_store;
int cs_pointer = 0;
int next_avail = 510;
int string_space = 0;
int entry_point = 0;

//TODO: Refactor main to series of function calls
int main(int argc, char** argv){

	if(argc < 2){
                printf("Please Provide a File Name\n");
                exit(1);
        }
        else{
                yyin = fopen(argv[1], "r");
        }
        //Check if the file exists and was able to be opened
        if(yyin == NULL){
                printf("Could Not Open File\n");
                exit(1);
        }
	int name_len = strlen(argv[1]);
	//printf("name_len: %d\n", name_len);
	char* output_file = malloc(sizeof(char)*name_len);
	strcpy(output_file, argv[1]);
	
	//Creating file with .pvm extension
	output_file[name_len - 4] = 'p';
	output_file[name_len - 3] = 'v';
	output_file[name_len - 2] = 'm';
	output_file[name_len - 1] = '\0';
	
	//innitialize codestore
	code_store =(int*) malloc(sizeof(int)*300);			
	yyparse();
	output = fopen(output_file, "wb");

	int i;
	//Putting header at top of the file
	fprintf(output, "%d %d %d %d\n",
			cs_pointer, next_avail, string_space, entry_point);
	
	for(i = 0; i < cs_pointer; i+=3){
		fprintf(output, "%d %d %d\n",
		code_store[i], code_store[i+1], code_store[i+2]);
	}
	//Adding strings to the bootom of the file
	if(string_list != NULL){	 
		list_node_t* list_node = string_list->head;
		int len;
		while(list_node != NULL){
			len = strlen(list_node->string);	
			i = 0;
			while(i < len){
				fprintf(output, "%d ", list_node->string[i]);
				i++;
			}	
			fprintf(output, "0\n");	
			list_node = list_node->next;
		}
	}


}
