#include <stdio.h>
#include <stdlib.h>

// Symbolic constant

#define TRUE 			0
#define FALE 			1

//Typedefination

typedef struct node node_t;
typedef size_t data_t;
typedef int status_t;

// struct decleration

struct node{
	data_t data;
	node_t* next;
};

node_t* create_list();	
void insert_start(node_t* head_node, size_t data);                                                                                                                                                               
void insert_end(node_t* head_node, size_t data);                                                                                                                                                                 
void insert_before(node_t* head_node, size_t before_data, size_t data);                                                                                                                                          
void insert_after(node_t* head_node, size_t after_data, size_t data);                                                                                                                                            

void get_start(node_t* head_node);                                                                                                                                                                               
void get_end(node_t* head_node);                                                                                                                                                                                 

void pop_start(node_t* head_node);                                                                                                                                                                               

void pop_end(node_t* head_node);                                                                                                                                                                                 
void remove_node(node_t* head_node, size_t delete_data);                                                                                                                                                         

void isEmpty(node_t* head_node);                                                                                                                                                                                 
void get_len(node_t* head_node);                                                                                                                                                                                 
void find(node_t* head_node, size_t search_data);                                                                                                                                                                
void show_list(node_t* head_node);
void destroy_list(node_t** p_head_node);

