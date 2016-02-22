#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct symtab_entry_s {

	char* name;
	char* type;
	int size;
	int location;
	struct symtab_entry_s* next;
}; 

struct symbol_table_s {

	int size;
	//initiallize array of pointers for the hash table
	struct symtab_entry_s** table;
};

typedef struct symtab_entry_s symtab_entry_t;
typedef struct symbol_table_s symbol_table_t;

char* mangle(char* proc, char* var);
symbol_table_t* create_symbol_table(int size);
uint32_t hash(char* identifier, int symbol_table_size);
int insert(char* name, char* type, int size, int location);
symtab_entry_t* lookup(char* identifier);
int print_symtab();
