#include "singly_list.hpp"

node::node(data_t data_t = 0) : data(data_t), next(0){

}

list::list() : head_node(new node){
}

list::~list(){
    node* run_next = 0;
    node* run = 0;

    run = head_node->next;
    for(; run != 0; run = run_next){
        run_next = run->next;
        delete run;
    }
    delete head_node;
    head_node = 0;
}

void list::insert_start(data_t new_data)
{
    generic_insert(head_node, new node(new_data));
}

void list::insert_end(data_t new_data){
    node* prev_node = 0;
    node* last_node = 0;

    last_node_and_prev(&prev_node, &last_node);
    generic_insert(last_node, new node(new_data));
}

void list::insert_after(data_t e_data, data_t new_data){
    node* prev_node = 0;
    node* current_node = 0;

    get_node_and_prev(e_data, &prev_node, &current_node);
    if(prev_node == 0 && current_node == 0){
        std::cout <<"List is empty" << std::endl;
        return;
    }
    generic_insert(prev_node, new node(new_data));
}

void list::insert_before(data_t e_data, data_t new_data){
    node* prev_node = 0;
    node* current_node = 0;

    get_node_and_prev(e_data, &prev_node, &current_node);

    if(prev_node == 0 && current_node == 0){
        std::cout <<"List is empty" << std::endl;
        return;
    }
    generic_insert(current_node, new node(new_data));
}

void list::get_start(){
    if(head_node->next == 0){
        std::cout <<"List is empty" << std::endl;
        return;
    }
    std::cout <<"Get_start() = " << head_node->next->data << std::endl;
}

void list::get_end(){
    if(head_node->next == 0){
        std::cout <<"List is empty" << std::endl;
        return;
    }
    node* prev_node = 0;
    node* last_node = 0;

    last_node_and_prev(&prev_node, &last_node);
    std::cout <<"Get_end() = " << last_node->data << std::endl;
}
void list::pop_start(){
    if(head_node->next == 0){
        std::cout <<"List is empty" << std::endl;
        return;
    }
    std::cout <<"pop_start() = " << head_node->next->data << std::endl;
    generic_delete(head_node, head_node->next);
}

void list::pop_end(){
    if(head_node->next == 0){
        std::cout <<"List is empty" << std::endl;
        return;
    }
    node* prev_node = 0;
    node* last_node = 0;

    last_node_and_prev(&prev_node, &last_node);
    std::cout <<"Get_end() = " << last_node->data << std::endl;
    generic_delete(prev_node, last_node);
}

void list::remove_node(data_t del_data){
    if(head_node->next == 0){
        std::cout <<"List is empty" << std::endl;
        return;
    }

    node* prev_node = 0;
    node* current_node = 0;

    get_node_and_prev(del_data, &prev_node, &current_node);
    if(prev_node == 0 && current_node == 0){
        std::cout <<"List is empty" << std::endl;
        return;
    }    
    generic_delete(prev_node, current_node);
}

void list::isEmpty(){
    if(head_node->next == 0){
        std::cout <<"List is empty" << std::endl;
        return;
    }
    std::cout <<"List is not empty"<< std::endl;
}

void list::get_len(){
    node* run = 0;
    data_t len = 0;

    run = head_node->next;
    while(run != NULL){
        len += 1;
        run = run->next;
    }
    std::cout <<"Len = "<<len << std::endl;
}

void list::find(data_t search_data){
    node* prev_node = 0;
    node* current_node = 0;

    get_node_and_prev(search_data, &prev_node, &current_node);
    if(prev_node == 0 && current_node == 0){
        std::cout <<"List is empty" << std::endl;
        return;
    }    
    if(current_node != 0)
        std::cout << "Data is present in the list" << std::endl;
    else        
        std::cout << "Data is not present in the list" << std::endl;
}

void list::generic_insert(node* prev_node, node* new_node){
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void list::generic_delete(node* prev_node, node* delete_node){
    prev_node->next = delete_node->next;
    delete delete_node;
    delete_node = 0;
}

void list::get_node_and_prev(data_t search_data, node** prev_node, node** current_node){
    node* start = 0;    
    node* end = 0;

    if(head_node->next != 0){
        start = head_node;
        end = head_node->next;

        while(end != 0){
            if(end->data == search_data)
                break;
            start = end;
            end = end->next;
        }
    }
    *prev_node = start;
    *current_node = end;
}

void list::last_node_and_prev(node** prev_node, node** last_node){
    node* start = 0;    
    node* end = head_node;

    if(head_node->next != 0){
        start = head_node;
        end = head_node->next;

        while(end->next != 0){
            start = end;
            end = end->next;
        }
    }
    *prev_node = start;
    *last_node = end;
}
