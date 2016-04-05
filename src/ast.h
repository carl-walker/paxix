#ifndef AST_H
#define AST_H

/**
 * program_node represents production 1 of our grammar and is the root node
 * for the AST.
 */
struct program_node {
	// globals_list and procedure_list would just hold these pointers anyway.
	struct globals_decl_node** globals;
	struct procedure_decl_node* procedures;
}

/**
 * Global variable declarations can be either array or integer typed.
 */
struct globals_decl_node {
	struct global_var_decl_node* var;
	struct array_decl_node* array;
}

/**
 * Multiple variables can be declared in each declaration.
 */
struct global_var_decl_node {
	struct global_var_node** global_vars;
}

/**
 * A declaration of a global variable needs only store the variables name.
 */
struct global_var_node {
	char* id;
}

/**
 * Array declarations can hold multiple arrays.
 */
struct array_decl_node {
	struct array_list_node* array_list;
}

struct array_list_node {
	struct array_node** arrays;
}

/**
 * The only information needed to store arrays is their size and id.
 */
struct array_node {
	char* id;
	int size;
}
#endif
