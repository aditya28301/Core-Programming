#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define INVALID_DATA -1
#define SUCESS 1
typedef struct node node_list;
typedef unsigned long long int data_t;

struct node
{
    data_t data;
    node_list* next;
};

static void generic_delete(node_list* prev, node_list* r_node);
static void generic_insert(node_list* prev, node_list* r_node);
void insert_start(node_list* head_node, data_t new_data);
void insert_end(node_list* head_node, data_t new_data);
static node_list* find_last_node(node_list* head_node);
void show_list(node_list* head_node);
node_list* create_list();
static void* xmalloc(data_t size);
static node_list* get_node(data_t new_data);
int get_start(node_list* head_node, data_t* first_data);
int get_end(node_list* head_node, data_t* last_data);
int pop_start(node_list* head_node, data_t* first_data);
int pop_end(node_list* head_node, data_t* last_data);
int remove_start(node_list* head_node);
int remove_end(node_list* head_node);
int insert_after(node_list* head_node, data_t e_data, data_t new_data);
int insert_before(node_list* head_node, data_t e_data, data_t new_data);
data_t list_length(node_list* head_node);
void destroy_list(node_list** head_node);