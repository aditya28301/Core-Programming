#include "Dcl.hpp"

list::list() : head_node(new node){
    head_node->next = head_node;
    head_node->prev = head_node;
}

void list::insert_start(data_t data){
    generic_insert(head_node, new node(data), head_node->prev);
}

void list::insert_end(data_t data){
    generic_insert(head_node->prev, new node(data), head_node);
}

void list::insert_after(data_t e_data, data_t data){
    node* e_node = 0;
    e_node = search_node(e_data);
    if(e_node == 0){
        std::cout <<"DATA IS INVALID" << std::endl;
        return;
    }
    generic_insert(e_node, new node(data), e_node->next);
    std::cout<<"insert after == Done"<< std::endl;
}
void list::insert_before(data_t e_data, data_t data){
    node* e_node = 0;
    e_node = search_node(e_data);
    if(e_node == 0){
        std::cout <<"DATA IS INVALID" << std::endl;
        return;
    }
    generic_insert(e_node->prev, new node(data), e_node);
    std::cout<<"insert before == Done"<< std::endl;
}
void list::get_start() const{
    if(isEmpty() == TRUE){

    }
}
void get_end() const ;
void pop_start();
void pop_end();
void remove_node(data_t delete_data);
void get_len() const;

void list::isEmpty() const{
    if(head_node->next == head_node && head_node->prev == head_node){
        std::cout <<"List is empty" << std::endl;
        return;
    }
    std::cout << "List is not empty" << std::endl;
}   

node::node(data_t data_t = 0) : data(data_t), next(0), prev(0){

}