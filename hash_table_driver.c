#include "hash_table.h"

extern hash_table_t* hash_table; 
int main(){
	int choice = 0;
	char input[256];
	char* identifier;
	char* type;
	printf("|-------------|\n");
	printf("| 1) Insert   |\n");
	printf("| 2) Lookup   |\n");
	printf("| 3) Quit     |\n");
	printf("|-------------|\n");
	printf("> ");
	scanf("%s", input);
	choice = atoi(input);
		
	while(choice != 3){

		switch(choice){
		
			case 1:
				//inserts new entry to symtab
				//initializing strings to size 80
				identifier = malloc(sizeof(char)*80);
				type = malloc(sizeof(char)*80);
				printf("Identifier: ");
				scanf("%s", identifier);
				printf("Type: ");
				scanf("%s", type);	
				int i =	insert(identifier, type, 0, 0);
				if(i == 0){
					 printf("Successfully Inserted\n");
					 break;
				} else{
					printf("Unable to Insert\n");
					break;
				} 
			
			case 2:
				//looking up entry in symtab
				identifier = malloc(sizeof(char)*80);
				printf("Identifier to lookup: ");
				scanf("%s", identifier);
				symtab_entry_t* entry = lookup(identifier);
				if(entry == NULL){
					 printf("Unable to Find\n");
				} else{
					printf("{%s, %s, %d, %d}\n",
					 entry->name,
					 entry->type,
					 entry->size,
					 entry->location);
				}
				break;
			
			default:
				printf("Command Not Recognized\n");
				break;
		}
		printf("|-------------|\n");
		printf("| 1) Insert   |\n");
		printf("| 2) Lookup   |\n");
		printf("| 3) Quit     |\n");
		printf("|-------------|\n");
		printf("> ");
		scanf("%d", &choice);
	}	
	print_symtab();
	exit(0);
}
