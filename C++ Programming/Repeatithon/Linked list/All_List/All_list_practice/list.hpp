#pragma once 

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <memory>

using data_t=long long int;

class node{
    friend class list;
    private:
        data_t data;
        node* next;

    public:
        node(data_t _data = 0);
        friend std::ostream& operator<<(std::ostream& os, list& rhs);
};

class list{
    private:
        // node* head_node;
        static void generic_insert(node* start, node* mid, node* end);
        void get_last_prev_node(node** prev_node, node** current_node);
        void find_current_prev_node(node** prev_node, node** current_node, data_t e_data);
        void generic_delete(node* start, node* d_node);

    public:
    node* head_node;
    list();
    list::list(list&& rhs);
    void insert_start(data_t new_data);
    void insert_end(data_t new_data);
    void insert_after(data_t e_data, data_t new_data);
    void insert_before(data_t e_data, data_t new_data);
    void get_start();
    void get_end();
    void pop_start();
    void pop_end();
    void remove_data(data_t d_data);
    bool isEmpty();
    void get_len();
    ~list();
    friend std::ostream& operator<<(std::ostream& os, list& rhs);
    list(list& rhs) = delete;
};
