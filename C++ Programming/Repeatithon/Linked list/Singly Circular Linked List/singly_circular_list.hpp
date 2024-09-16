#ifndef _SINGLY_CIRCULAR_
#define _SINGLY_CIRCULAR_

/* Header files */
#include <cstdio>
#include <cstdlib>
#include <iostream>

/* Symbolic constant    */
const int TRUE  = 1;
const int FALSE = 2;
const int EMPTY_LIST = 3;
const int INVALID_DATA = 4;

/* Type defination  */
typedef unsigned long long int data_t;
typedef int status_t;

/* Class decleration    */
class node{
    friend class list;
    private:
        data_t data;
        node* next;
        node(data_t data_ = 0);
};

class list{
    private:
        node* head_node;
        static void generic_insert(node* prev, node* next);
        static void generic_delete(node* prev_node, node* del_node);
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
        void remove_data(data_t e_data);
        void get_len();
        void isEmpty();
        void get_node_and_prev_node(data_t e_data, node** current_node , node** prev_node);
        void last_node_and_prev_node(node** last_node, node** prev_node);
        void show_list();
};

#endif /*   _SINGLY_CIRCULAR_   */