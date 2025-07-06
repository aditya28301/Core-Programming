#ifndef _SINGLY_LIST_
#define _SINGLY_LIST_
/* Header file decleration  */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>

/* Symbolic constant    */
const int TRUE         =    1;
const int FALSE        =    2;
const int INVALID_DATA =    3;
const int EMPTY_LIST   =    4;

/* typedefination   */
typedef unsigned long long int data_t;
typedef int status_t;

/* Class decleration    */
class node{
    friend class list;
    private:
        data_t data;
        node* next;

    public:
        node(data_t data_t);
};

class list{
    private:
        node* head_node;
        void generic_insert(node* prev_node, node* new_node);
        void generic_delete(node* prev_node, node* delete_node);

    public:
        list();
        ~list();
        void insert_start(data_t new_data);
        void insert_end(data_t new_data);
        void insert_after(data_t e_data, data_t new_data);
        void insert_before(data_t e_data, data_t new_data);
        void get_start();
        void get_end();
        void pop_start();
        void pop_end();
        void remove_node(data_t del_data);
        void isEmpty();
        void get_len();
        void find(data_t search_data);
        void get_node_and_prev(data_t search_data, node** prev_node, node** current_node);
        void last_node_and_prev(node** prev_node, node** last_node);
};

#endif  /*_SINGLY_LIST_ */