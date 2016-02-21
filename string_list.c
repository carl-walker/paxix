#include "string_list.h"

string_list_t* string_list = NULL;

string_list_t* create_string_list(){
	string_list_t* new_list = malloc(sizeof(string_list_t));
	new_list->head = NULL;
	new_list->tail = NULL;
	return new_list;
}

list_node_t* create_list_node(char* string){
	list_node_t* new_node = malloc(sizeof(list_node_t));
	new_node->string = string;
	new_node->next = NULL;
	return new_node;

}

int add_string(char* string){
	if(string_list == NULL){
		string_list = create_string_list();
	}		
	list_node_t* new_node = create_list_node(string);
	//inserting first string into list
	//saves node as head and tail
	if(string_list->head == NULL){
		//creates a new node with string as member
		string_list->head = new_node;
		string_list->tail = new_node;
		return 0;
	}
	//add node to the end of the list and make it the tail
	string_list->tail->next = new_node;
	string_list->tail=new_node;
	return 0;
}

void print_list(){
	if(string_list == NULL){
		return;
	}
	list_node_t* node = string_list->head;
	while(node->next != NULL){
		printf("%s -> ", node->string);
		node = node->next;
	}
	printf("%s\n", node->string);
}
