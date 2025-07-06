/* Header files */
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>

/* Symbolic constant    */
const int TRUE =            1;
const int FALSE =           2;
const int LIST_EMPTY =      3;
const int DATA_INVALID =    4;

/* Type defination  */
typedef unsigned long long int data_t;

/* Class Decleration    */
class node{
    private:
        friend class list;
        data_t data;
        node* next;
        node* prev; 
    public:
        node(data_t data = 0);
};

class list{
    private:
        node* head_node;
        static generic_insert(node* start, node* mid, node* end);
        static generic_delete(node* delete_node);
        node* search_node(data_t search_data) const;

    public:
        list();
        ~list();
        void insert_start(data_t data); 
        void insert_end(data_t data);
        void insert_after(data_t e_data, data_t data);
        void insert_before(data_t e_data, data_t data);
        void get_start() const;
        void get_end() const ;
        void pop_start();
        void pop_end();
        void remove_node(data_t delete_data);
        void get_len() const;
        void isEmpty() const;    
};