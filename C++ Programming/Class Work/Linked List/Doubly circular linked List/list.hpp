/*  GUARD   */
#ifndef _LIST_CPP_
#define _LIST_CPP_

/*  Header Files    */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cassert>

/*  Symbolic Constant   */
const int SUCCESS =                 0;
const int LIST_EMPTY =              1;
const int TRUE =                    2;
const int FALSE =                   3;
const int LIST_INVALID_DATA =       4;
const int TEST_DATA =               10;

/*  Typedef */
typedef int status_t;
typedef int data_t; 
typedef unsigned long long int size_t;

/*  Function Decleration    */
void run(void);

/*  Node Class  */
class node{
    friend class list;
    private:
        data_t data;
        node* prev;
        node* next;
        node(data_t _data = 0);
};

/*  List Class  */
class list{
    private:
        node* head_node;
        node* search_node(data_t e_data);
        static void generic_insert(node* start, node* mid, node* end);
         static void generic_delete(node* d_node);
    public:
        list();
        ~list();
        status_t insert_start(data_t new_data);
        status_t insert_end(data_t new_data);
        status_t insert_after(data_t e_data, data_t new_data);
        status_t insert_before(data_t e_data, data_t new_data);
        status_t get_start(data_t* st_data);
        status_t get_end(data_t* ed_data);
        status_t pop_start(data_t* st_data);
        status_t pop_end(data_t* ed_data);
        status_t remove_node(data_t e_data);
        status_t get_len(size_t* len);
        status_t isEmpty();
        status_t find(data_t s_data);
};
#endif      /*  _LIST_CPP_    */