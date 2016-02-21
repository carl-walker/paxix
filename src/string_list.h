#ifndef _STDIO_H_
#define _STDIO_H_
#include <stdio.h>
#endif

#ifndef _STDLIB_H
#define _STDILIB_H_
#include <stdlib.h>
#endif

struct list_node_s {
	char* string;
	struct list_node_s* next;
};

struct string_list_s {
	struct list_node_s* head;
	struct list_node_s* tail;
};

typedef struct string_list_s string_list_t;
typedef struct list_node_s list_node_t;

string_list_t* create_string_list();
list_node_t* create_list_node(char* string);
int add_string(char* string);
void print_list();
