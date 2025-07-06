#include <iostream>
#include <cstdlib>
#include "Istack.hpp"

/* Typedefination */
typedef size_t data_t;

class node{
    friend class list;
    private:
        data_t data;
        node* next;

    public:
        node(data_t new_data);
};

class list : public Istack{
    private:
        node* head_node;
        data_t size;

        /* Auxilary funtion */
        void insert_end(data_t new_data);
        data_t get_end();
        void pop_end();
        bool isEmpty();
        void show_list();
        data_t get_len();
        bool capacity();

        // Helper function
        void get_last_and_prev_node(node** prev_node, node** current_node);
        void last_and_prev_node(node** prev_node, node** current_node);
        node* find_node(data_t e_data);

    public:
        list(data_t _size);  
        void push(data_t new_data);    
        void pop();
        void peek();
        void display();
        void empty();
        bool isFull();
        ~list();
};
