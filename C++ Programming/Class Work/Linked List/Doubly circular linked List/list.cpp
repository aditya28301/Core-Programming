#include "list.hpp"

node::node(data_t _data) : data(_data), next(0), prev(0){
}

list::list() : head_node(new node){
    head_node->next = head_node;
    head_node->prev = head_node;
}

list::~list(){
    node* run_next = 0;
    node* run = 0;

    run = head_node->next;
    while(run != head_node){
        run_next = run->next;
        delete run;
        run = run_next;
    }
    delete head_node;
}
status_t list:: insert_start(data_t new_data){
    generic_insert(head_node, new node(new_data), head_node->next);
    return SUCCESS;
}   

status_t list:: insert_end(data_t new_data){
    generic_insert(head_node->prev, new node(new_data), head_node);
    return SUCCESS;
}

status_t list::insert_after(data_t e_data, data_t new_data){
    node* s_node = 0;
    s_node = search_node(e_data);
    generic_insert(s_node, new node(new_data), s_node->next);
    return SUCCESS;
}

status_t list::insert_before(data_t e_data, data_t new_data){
    node* s_node = 0;
    s_node = search_node(e_data);
    assert(s_node != 0);
    generic_insert(s_node->prev, new node(new_data), s_node);
    return SUCCESS;
}

status_t list::get_start(data_t* st_data){
    *st_data = head_node->next->data;
    return SUCCESS;
}

status_t list::get_end(data_t* ed_data){
    *ed_data = head_node->prev->data;
    return SUCCESS;
}

status_t list::pop_start(data_t* st_data){
    assert(isEmpty() == FALSE);
    *st_data = head_node->next->data;
    generic_delete(head_node->next);
    return SUCCESS;
}

status_t list::pop_end(data_t* ed_data){
    assert(isEmpty() == FALSE);
    *ed_data = head_node->prev->data;
    generic_delete(head_node->prev);
    return SUCCESS;
}
status_t list::remove_node(data_t e_data){
    node* s_node = 0;
    s_node = search_node(e_data);
    assert(s_node != 0);
    generic_delete(s_node);
    return SUCCESS;
}
status_t list::get_len(size_t* len){
    node* run = 0;
    for(run = head_node->next; run != head_node; run = run->next){
        *len = *len + 1;
    }
    return SUCCESS;
}

status_t list::isEmpty(){
    if(head_node->next != 0)
        return FALSE;
    return TRUE;
}

void list::generic_insert(node* start, node* mid, node* end){
    mid->prev = start;
    mid->next = end;
    start->next = mid;
    end->prev = mid;
}

void list::generic_delete(node* d_node){
    node* start = 0;
    node* end = 0;

    start = d_node->prev;
    end = d_node->next;

    start->next = end;
    end->prev = start;
    delete d_node;
}

node* list::search_node(data_t e_data){
    node* run = 0;
    for(run = head_node->next; run != head_node; run = run->next){
        if(e_data == run->data)
            return run;
    }
    return 0;
}

status_t list::find(data_t s_data){
    node* s_node = 
    s_node = search_node(s_data);
    assert(s_node != 0);
    return TRUE;
}

void run(void){
    int data;
    size_t len = 0;
    status_t status;

    std::cout <<"LIST CREATED" <<std::endl;
    list* p_list = new list;

    std::cout <<"INSERT END" <<std::endl;
    for(size_t i = 0; i < TEST_DATA; ++i){
        status = p_list->insert_end((i + 1) * 1000);
        if(status == SUCCESS)
            std::cout <<"Insert End "<<(i + 1) * 1000 <<std::endl;
    }

    std::cout <<"INSERT START" <<std::endl;
    p_list->insert_start(-99);

    std::cout <<"INSERT AFTER" <<std::endl;
    p_list->insert_after(2000, -222);

    std::cout <<"GET LENGHT OF LIST" <<std::endl;
    p_list->get_len(&len);
    std::cout <<"LENGHT IS= "<<len <<std::endl;

    std::cout <<"GET START NODE DATA" << std::endl;
    p_list->get_start(&data);
    std::cout <<"START DATA IS= "<<data <<std::endl;

    std::cout <<"GET END NODE DATA" <<std::endl;
    p_list->get_end(&data);
    std::cout <<"END NODE DATA= "<< data <<std::endl;

    std::cout <<"REMOVE DATA" <<std::endl;
    p_list->remove_node(-99);

    std::cout <<"POP START" <<std::endl;
    p_list->pop_start(&data);
    std::cout <<"POP START DATA IS= " <<data <<std::endl;

    std::cout <<"POP END" <<std::endl;
    p_list->pop_end(&data);
    std::cout <<"POP END DATA IS= " <<data <<std::endl;

    std::cout <<"FIND DATA"<< std::endl;
    if(p_list->find(2000) == TRUE)
        std::cout<<"DATA IS PRESENT"<< std::endl;

    std::cout <<"LIST EMPTY CHECK"<< std::endl;
    p_list->isEmpty();

    std::cout <<"DESTORY LIST"<< std::endl;
    delete p_list;
    p_list = 0;
}