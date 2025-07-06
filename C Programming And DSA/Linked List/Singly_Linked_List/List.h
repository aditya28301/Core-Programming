/* Header file decleration  */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

/* Symbolic constant    */
#define TRUE    1
#define FALSE   2

/* Typedefination   */
typedef unsigned long long int data_t;
typedef int status_t;
typedef struct node node_t;
typedef node_t list_t;

/* struct decleration   */
struct node{
    data_t data;
    struct node* next;
};

/* Interface function   */
list_t* create_list(void);
void insert_start(list_t* list, data_t new_data);
void insert_end(list_t* list, data_t new_data);
void insert_after(list_t* list, data_t e_data, data_t new_data);
void insert_before(list_t* list, data_t e_data, data_t new_data);
void pop_start(list_t* list);
void pop_end(list_t* list);
void get_start(list_t* list);
void get_end(list_t* list);
void get_start(list_t* list);
void remove_node(list_t* list, data_t e_data);
status_t isEmpty(list_t* list);
void get_len(list_t* list);
void show(list_t* list);
void destroy_list(list_t** pp_list);
list_t* concat(list_t* list1, list_t* list2);
void append(list_t* list1, list_t* list2);
list_t* merge(list1, list2);
void reverse_list(list_t* list1);

/*  Helper function */
node_t* get_node(data_t new_data);
void* xmalloc(data_t new_required_byte);
void get_node_prev_node(list_t* list, data_t e_data,    node_t** current_node, node_t** prev_node);
void last_node_prev_node(list_t* list, node_t** last_node, node_t** prev_node);

/* Auxilary function    */
void generic_insert(node_t* start, node_t* new_node);
void generic_delete(node_t* prev_node, node_t* del_node);