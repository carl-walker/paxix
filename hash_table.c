#include "hash_table.h"

hash_table_t* hash_table = NULL;

// Creates a new hash_table with 'size' entries
hash_table_t* create_hash_table(int size){
	
	int i;
	//intitialize the struct which holds the information about the hashtable
	hash_table = malloc(sizeof(hash_table_t));
	
	if(hash_table == NULL){
		printf("ERROR: UNABLE TO INITIALIZE HASH TABLE\n");
		exit(1);
	}
	//intitialize the array of pointers which is the hash_table
	hash_table->table = malloc(sizeof(symtab_entry_t*) * size);

	if(hash_table->table == NULL){
		printf("ERROR: UNABLE TO INITIALIZE HASH TABLE NODES\n");
		exit(1);
	}
	//NULLing out table entries
	for(i = 0; i < size; i++){
		hash_table->table[i] = NULL;	
	}
	hash_table->size = size;
	return hash_table;
}

//Function to create a symtab_entry given appropriate fields
symtab_entry_t* create_symtab_entry(char* name, char *type, 
				    int size, int location){

	symtab_entry_t* new_entry = malloc(sizeof(symtab_entry_t));
	new_entry->name = name;
	new_entry->type = type;
	new_entry->size = size;
	new_entry->location = location;
	return new_entry; 

}

// Hash function for inserting into the hashtable
uint32_t hash(char* identifier, int hash_table_size){
	uint32_t hash, len;
	hash = len = 0;
	while(identifier[len] != '\0'){
		hash += identifier[len];
		hash += (hash << 7);
        	hash ^= (hash >> 2);
		len++;
	}
	hash = (hash % hash_table_size);
	return hash;
}

//check if the entry already exists in the hash table
// if it does, return 1, else insert and return 0
int insert(char* name, char* type, int size, int location){
	
	//create the hash table on first insert
	if(hash_table == NULL){
		hash_table = create_hash_table(9001);
	}
		
	symtab_entry_t* entry = create_symtab_entry(name, type, size, location);
	uint32_t bucket = hash(entry->name, hash_table->size);
	
	//bucket is empty
	if(hash_table->table[bucket] == NULL){;
		hash_table->table[bucket] = entry;
		return 0;
	}
	
	//bucket is non-empty, search synonym chain for identifier
	symtab_entry_t* existing_entry = hash_table->table[bucket];
	//TODO: refactor this block of code
	while(existing_entry->next != NULL){
		if(!strcmp(existing_entry->name, entry->name)){
			//printf("Entry already exists\n");
			return 1;
		}
		existing_entry = existing_entry->next;
	}
	if(!strcmp(existing_entry->name, entry->name)){
		return 1;
	} else{
		existing_entry->next = entry;
		return 0;
	}

}

//searches the hash table for an entry with name identifier
//returns pointer to entry if found, else returns null. 
symtab_entry_t* lookup(char* identifier){

	if(hash_table == NULL){
		return NULL;
	}
	
	uint32_t bucket = hash(identifier, hash_table->size);
	
	if(hash_table->table[bucket] == NULL){
		return NULL;
	} 
	symtab_entry_t* entry = hash_table->table[bucket];
	while(entry != NULL){
		if(!strcmp(entry->name, identifier)){
			return entry;
		} else{
			entry = entry->next;
		}
	}
	return NULL;
}

//for testing purposes
int print_bucket(int bucket){

	symtab_entry_t* entry = hash_table->table[bucket];
	if(entry != NULL){
		while(entry->next != NULL){
			printf("{%s, %s, %d, %d} -> ",
			entry->name, entry->type, entry->size, entry->location);
			entry = entry->next;
		}
	printf("{%s, %s, %d, %d}\n",
	entry->name, entry->type, entry->size, entry->location);
	return 0;
	}
}

//for testing purposes
int print_symtab(){
	int i;
	if(hash_table == NULL){
		return 1;
	}
	for(i = 0; i < hash_table->size; i++){
		print_bucket(i);
	}

	return 0;
}

