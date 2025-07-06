#include "stack.hpp"

node::node(data_t new_data = 0) : data(new_data), next(0){
}

list::list(data_t _size) : head_node(new node), size(_size)
{ 
    std::cout <<"EMPTY LIST IS CREATED" << std::endl; 
}

void list::push(data_t new_data){
    insert_end(new_data);    
}

void list::pop(){
    pop_end();
}

void list::peek(){
    data_t top = 0;
    top = get_end();
    std::cout <<"TOP ELEMENT IS = " << top << std::endl;
}

void list::display(){
    show_list();
}

void list::empty(){
    bool status = false;
    status = isEmpty();
    if(status == true)
        std::cout <<"STACK IS EMPTY" << std::endl;
    else      
        std::cout <<"STACK IS NOT EMPTY" << std::endl;
}

list:: ~list(){
    node* run = 0;
    node* run_next = head_node->next;

    while(run_next != 0){
        run = run_next->next;
        free(run_next);
        run_next = run->next;
    }
    free(head_node);
    head_node = 0;
}

void list:: insert_end(data_t new_data){
    node* prev_node = 0;
    node* current_node = 0;

    last_and_prev_node(&prev_node, &current_node);
    if(current_node == 0 && prev_node == 0){
        current_node = head_node;
    }
    
    node* new_node = new node(new_data);
    current_node->next = new_node;
}

data_t list:: get_end(){
    node* prev_node = 0;
    node* current_node = 0;

    last_and_prev_node(&prev_node, &current_node);
    if(prev_node == 0 && current_node == 0){
        std::cout <<"STACK IS EMPTY" << std::endl;
        return 0;
    }
    return current_node->data;
}

void list:: pop_end(){
    node* prev_node = 0;
    node* current_node = 0;

    last_and_prev_node(&prev_node, &current_node);  
    prev_node->next = current_node->next;
    std::cout <<"Element is pop = " <<current_node->data << std::endl;
    free(current_node);
}

bool list:: isEmpty(){
    if(head_node->next == 0){
        return true;
    }
    return false;
}

void list:: show_list(){
    node* run = head_node->next;
    std::cout <<"[START]";
    while(run != 0){
        std::cout <<"["<<run->data <<"]->";
        run = run->next;
    }
    std::cout <<"[END]" << std::endl;
}       

data_t list:: get_len(){
    data_t len = 0;
    node* run = head_node->next;
    
    while(run != 0){    
        len = len + 1;
        run = run->next;
    }
    return len;
}

void list::last_and_prev_node(node** prev_node, node** current_node){

    node* run = 0;
    node* run_next = 0;

    if(head_node->next != 0){
        run = head_node;
        run_next = head_node->next; 

        while(run_next->next != 0){
            run = run_next;
            run_next = run_next->next;
        }          
    }

    *prev_node = run;
    *current_node = run_next;
}

bool list::isFull(){
    if(get_len() < size){
        return false;
    }
    return true;
}

Istack* Istack::get_instance(data_t size){
    return new list(size);
}

void Istack::Release_instance(Istack* istack){

}
