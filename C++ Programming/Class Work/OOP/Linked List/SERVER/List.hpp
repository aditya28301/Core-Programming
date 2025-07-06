#ifndef _LIST_
#define _LIST_
#include "IList.hpp"

const int INVALID_DATA  = 0;
const int LIST_IS_EMPTY = 1;
const int TRUE = 3;
const int FAILURE = 4;
const unsigned int TEST_MAX = 5;
const int DATA_PRESENT = 6;
const int LIST_NOT_EMPTY = 7;

class node{
    friend class List;
    private:
        data_t data;
        node* next;
        node* prev;
    public:
        node(data_t data_ = 0);
};

class List : public IList{
    private:
        node* head_node;
        static void generic_insert(node* start, node* mid, node* end);
        static void generic_delete(node* d_node);
        node* search_node(data_t data);
    public:
        ~List();
        List();
        void insert_start(data_t data);
        void insert_end(data_t data);
        void insert_after(data_t e_data, data_t data);
        void insert_before(data_t e_data, data_t data);
        void get_start(data_t* g_data);
        void get_end(data_t* g_data);
        void pop_start(data_t* g_data);
        void pop_end(data_t* g_data);
        status_t find(data_t s_data);
        status_t isEmpty();
        data_t getLen();
        void show();
};

#endif //_LIST_