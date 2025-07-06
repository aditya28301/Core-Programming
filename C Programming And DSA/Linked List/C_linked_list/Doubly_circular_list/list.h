#include <stdio.h>
#include <stdlib.h>

// Symbolic constant
#define TRUE	1
#define FALSE	0

// Typedefination
typedef size_t data_t;
typedef struct node node_t;
typedef int status_t;

struct node{
	size_t data;
	struct node* next;
	struct node* prev;
};

// Interface function
node_t* create_list(void);
void insert_start(node_t* head_node, data_t new_data);
void insert_end(node_t* head_node, data_t new_data);
void insert_after(node_t* head_node, data_t e_data, data_t new_data);
void insert_before(node_t* head_node, data_t e_data, data_t new_data);
void get_start(node_t* head_node);
void get_end(node_t* head_node);
void pop_start(node_t* head_node);
void pop_end(node_t* head_node);
void remove_node(node_t* head_node, data_t del_node);
void get_len(node_t* head_node);
status_t isEmpty(node_t* head_node);
void show_list(node_t* head_node);
void destroy_list(node_t** p_head_node);

// Auxilairy function
static void generic_insert(node_t* start, node_t* mid, node_t* end);
static void generic_delete(node_t* start, node_t* del_node);
static node_t* find_node(node_t* head_node, data_t s_data);

// Helper function
node_t* get_node(data_t new_data);
void* xmalloc(data_t new_required_byte);

