#include <stdio.h>
#include <stdlib.h>

#ifndef _STRING_LIST_H_
#define _STRING_LIST_H_
#include "string_list.h"
#endif

#include "paxi_parser.tab.h"

extern FILE* yyin;
extern char* yytext;
extern string_list_t* string_list;
extern struct hash_table_s* hash_table;

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
	int token_returned = 1;

	while(token_returned != 0){
		token_returned = yylex();
		printf("Token %d ", token_returned);
		//TODO: Make test driver to spec
		//add printing recognized int, identifier, or string
		if(token_returned == ID_TOKEN){
			printf("Identifier: %s", yytext);
		}
		if(token_returned == INT_TOKEN){
			printf("Integer: %s", yytext);
		}
		if(token_returned == STRING_TOKEN){
			printf("String: %s", yytext);
		}
		printf("\n");
	}

//	yyparse();
//	print_symtab();
//	add_string("\"test\"");
//	add_string("\"hello world\"");
//	add_string("\"foo\"");

	print_list();
}
