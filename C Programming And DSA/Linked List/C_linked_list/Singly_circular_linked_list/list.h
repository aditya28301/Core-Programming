#include <stdio.h>
#include <stdlib.h>

// typedefination
typedef size_t data_t;

// strcuture declearation
struct node{
    size_t data;
    struct node* next;
};

typedef struct node node_t;

// list interface calling function
node_t*  create_list();
void insert_start(node_t* head_node, data_t new_data);
void insert_end(node_t* head_node, data_t new_data);
void insert_before(node_t* head_node, data_t e_data, data_t new_data);
void insert_after(node_t* head_node, data_t e_data, data_t new_data);
void get_start(node_t* head_node);
void get_end(node_t* head_node);
void pop_start(node_t* head_node);
void pop_end(node_t* head_node);
void remove_node(node_t* head_node, data_t d_data);
void get_len(node_t* head_node);
void show_list(node_t* head_node);
void destroy_list(node_t** head_node);