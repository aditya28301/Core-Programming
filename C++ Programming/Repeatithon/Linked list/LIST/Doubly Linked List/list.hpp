/* Header file declaration  */
#include <cstdio>
#include <cstdlib>
#include <iostream>

/* Symbolic constatnt   */
const int TRUE  = 1;
const int FALSE  = 2;

/* Typedefination */
typedef unsigned long long int data_t;
typedef int status_t;

/* Class decleration    */
class node{
    friend class list;
    private:
        data_t data;
        node* next;
        node* prev;
        node(data_t data_t = 0);
};

class list{
    private:
        node* head_node;
        static void generic_insert(node* start, node* new_node);
        static void generic_delete(node* del_node);
        node* search_node(data_t e_data);
        node* get_last_node() const;
    public:
    list();
    ~list();
    void show() const;
    void insert_start(data_t new_data);
    void insert_end(data_t new_data);
    void insert_after(data_t e_data, data_t new_data);
    void insert_before(data_t e_data, data_t new_data);
    void get_start() const;
    void get_end() const;
    void pop_start();
    void pop_end();
    void remove_node(data_t e_data);
    void get_len() const;
    status_t isEmpty() const;
};

