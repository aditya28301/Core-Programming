#include "list.hpp"
list::~list(){
    node* run = 0;
    node* run_next = 0;

    run = head_node->next;
    for(; run != 0; run = run_next){
        run_next = run->next;
        free(run);
    }

    delete head_node;
    head_node = 0;
}

void list::show() const{
    node* run = 0;
    run = head_node->next;

    std::cout << "[START]" << std::endl;
    while(run != 0)
    {
        std::cout <<"[" <<run->data <<"]"; 
        run = run->next;
    }
    std::cout << "[END]" << std::endl;
}

node::node(data_t data_t) : next(0), prev(0), data(data_t){
    
}

list::list() : head_node(new node){
        head_node->next = 0;
        head_node->prev = 0;
}

void list::insert_start(data_t new_data){
    generic_insert(head_node, new node(new_data));
}

void list::insert_end(data_t new_data){
    node* last_node = 0;
    last_node = get_last_node();
    generic_insert(last_node, new node(new_data));
}

void list::insert_after(data_t e_data, data_t new_data){
    if(isEmpty() == TRUE){
        std::cout <<"List is empty" << std::endl;
        return;
    }
    node* e_node = 0;
    e_node = search_node(e_data);
    if(e_node == 0){
        std::cout <<"Invalid data" << std::endl;
    }
    generic_insert(e_node, new node(new_data));
}

void list::insert_before(data_t e_data, data_t new_data){
    if(isEmpty() == TRUE){
        std::cout <<"List is empty" << std::endl;
        return;
    }
    node* e_node = 0;
    e_node = search_node(e_data);
    if(e_node == 0){
        std::cout <<"Invalid data" << std::endl;
    }
    generic_insert(e_node->prev, new node(new_data));

}
void list::get_start() const{
    if(isEmpty() == TRUE){
        std::cout <<"List is empty" << std::endl;
        return;
    }
    std::cout <<"get_start() = " << head_node->next->data << std::endl;
}

void list::get_end() const{
    if(isEmpty() == TRUE){
        std::cout <<"List is empty" << std::endl;
        return;
    }

    node* last_node = 0;
    last_node = get_last_node();
    std::cout <<"get_last() = "<< last_node->data << std::endl;
}

void list::pop_start(){
    if(isEmpty() == TRUE){
        std::cout <<"List is empty" << std::endl;
        return;
    }
    std::cout <<"get_last() = "<< head_node->next->data << std::endl;
    generic_delete(head_node->next);
}

void list::pop_end(){
    if(isEmpty() == TRUE){
        std::cout <<"List is empty" << std::endl;
        return;
    }

    node* last_node = 0;
    last_node = get_last_node();
    std::cout <<"get_last() = "<< last_node->data << std::endl;
    generic_delete(last_node);
}

void list::remove_node(data_t e_data) {
    if(isEmpty() == TRUE){
        std::cout <<"List is empty" << std::endl;
        return;
    }

    node* e_node = 0;
    e_node = search_node(e_data);
    generic_delete(e_node);
}

void list::get_len() const {
    node* run = 0;
    data_t len = 0;
    run = head_node->next;
    while(run != 0){
        len+= 1;
        run = run->next;
    }
    std::cout <<"length of list is = " << len << std::endl;
}

status_t list::isEmpty() const {
    if(head_node->next == 0)
        return TRUE;
    return FALSE;
}

node* list::get_last_node() const{
    node* run = 0;
    run = head_node->next;
    while(run->next != 0){
        run = run->next;
    }
    return run;
}

void list::generic_insert(node* start, node* new_node){
    new_node->next = start->next;
    new_node->prev = start;
    start->next = new_node;
    if(new_node->next != 0)
        new_node->next->prev = new_node;
}

void list::generic_delete(node* del_node){
    node* start = 0;
    node* end = 0;
    
    start = del_node->prev;
    end = del_node->next;

    start->next = end;
    if(end != 0)
        end->prev = start;
    delete del_node;
}

node* list::search_node(data_t e_data){
    node* run = 0;
    run = head_node->next;
    while(run != 0){
        if(run->data == e_data)
            return run;
        run = run->next;
    }
    return 0;
}   