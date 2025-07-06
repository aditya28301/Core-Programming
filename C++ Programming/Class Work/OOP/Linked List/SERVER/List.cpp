#include "List.hpp"

node::node(data_t data_) : data(data_), next(0), prev(0){

}
List::List() : head_node(new node){
    head_node->next = head_node;
    head_node->prev = head_node;
}
void List:: generic_insert(node* start, node* mid, node* end){
    mid->prev = start;
    mid->next = end;
    start->next = mid;  
    end->prev = mid;
}

void List:: generic_delete(node* d_node){
    node* start = 0;
    node* end = 0;

    start = d_node->prev;
    end = d_node->next;

    start->next = end;
    end->prev = start;
    delete d_node;
}

node* List::search_node(data_t data){
    node* run = 0;
    run = head_node->next;
    for(;run != head_node; run = run->next){
        if(run->data == data)
            return run;
    }
    return 0;
}

void List::insert_start(data_t data){
    generic_insert(head_node, new node(data), head_node->next);
}

void List::insert_end(data_t data){
    generic_insert(head_node->prev, new node(data), head_node);
}

void List::insert_after(data_t e_data, data_t data){
    node* e_node = 0;
    e_node = search_node(e_data);
    if(e_node == 0){
        std::cout << "INVALID DATA " << std::endl;
        exit(EXIT_FAILURE);
    }
    generic_insert(e_node, new node(data), e_node->next);
}

void List::insert_before(data_t e_data, data_t data){
    node* e_node = 0;
    e_node = search_node(e_data);
    if(e_node == 0){
        std::cout << "INVALID DATA " << std::endl;
        exit(EXIT_FAILURE);
    }
    generic_insert(e_node->prev, new node(data), e_node);
}

void List::get_start(data_t* g_data){
    *g_data = head_node->next->data;
}

void List::get_end(data_t* g_data){
    *g_data = head_node->prev->data;
}

void List::pop_start(data_t* g_data){
    *g_data = head_node->next->data;
    generic_delete(head_node->next);
}

void List::pop_end(data_t* g_data){
    *g_data = head_node->prev->data;
    generic_delete(head_node->prev);
}

status_t List::find(data_t s_data){
    node* e_node = 0;
    e_node = search_node(s_data);
    if(!e_node)
        return INVALID_DATA;
    return DATA_PRESENT;
}

status_t List::isEmpty(){
    if(head_node->next == head_node && head_node->prev == head_node)    
        return LIST_IS_EMPTY;
    return LIST_NOT_EMPTY;
}

data_t List::getLen(){
    unsigned int len = 0;
    node* run = 0;
    run = head_node->next;
    for(; run != head_node; run = run->next){
        len += 1;
    }
    return len;
}

List::~List(){
    std::cout <<"List destructor called"<< std::endl;
    node* run = 0;
    node* run_next = 0;

    run = head_node->next;
    for(;run != head_node; run = run_next){
        run_next = run->next;
        delete run;
    }
    delete head_node;
    head_node = 0;
}

IList* IList:: get_instance(){
    return new List;
}
void IList:: release_instance(IList* release){
    delete release;
}

void List::show(){
    if(head_node == 0)
    {   
        std::cout <<"List is empty" << std::endl;   
        return;
    }
    node* run = 0;
    run = head_node->next;
    std::cout <<"[START]->";
    for(; run != head_node; run = run->next){
        std::cout <<"[" << run->data <<"]";
    }
    std::cout <<"<-[END]" << std::endl;
}