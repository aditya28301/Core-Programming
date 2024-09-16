#include "singly_circular_list.hpp"

list::list() : head_node(new node){
    head_node->next = head_node;
}
list::~list(){
    node* run = 0;
    node* run_next = 0;

    run = head_node->next;
    for(; run != head_node; run = run_next){
        run_next = run->next;
        free(run);
    }

    delete head_node;
    head_node = 0;
}

node::node(data_t data_) : data(data_), next(0){

};

void list::insert_start(data_t new_data)
{
    generic_insert(head_node, new node(new_data));
}

void list::insert_end(data_t new_data){
    node* last_node  = 0;
    node* prev_node = 0;
    last_node_and_prev_node(&last_node, &prev_node);
    if(last_node == 0 || prev_node == 0){
        std::cout <<"list is empty"<< std::endl;
        return;
    }

    generic_insert(last_node, new node(new_data));
}

void list::insert_after(data_t e_data, data_t new_data){
    if(head_node->next == head_node){
        std::cout << "List is empty" << std::endl;
        return;
    }

    node* prev_node = 0;
    node* current_node = 0;
    get_node_and_prev_node(e_data, &current_node, &prev_node);
    if(prev_node == 0 || current_node == 0){
        std::cout <<"Invalid data"<< std::endl;
        return;
    }
    generic_insert(current_node, new node(new_data));
}

void list::insert_before(data_t e_data, data_t new_data){
    if(head_node->next == head_node){
        std::cout << "List is empty" << std::endl;
        return;
    }

    node* prev_node = 0;
    node* current_node = 0;
    get_node_and_prev_node(e_data, &current_node, &prev_node);
    if(prev_node == 0 || current_node == 0){
        std::cout <<"Invalid data"<< std::endl;
        return;
    }
    generic_insert(prev_node, new node(new_data));
}

void list::get_start(){
    if(head_node->next == head_node){
        std::cout << "List is empty" << std::endl;
        return;
    }
    std::cout <<"get_start()"<< head_node->next->data << std::endl;
}

void list::get_end(){
    if(head_node->next == head_node){
        std::cout << "List is empty" << std::endl;
        return;
    }
    node* prev_node = 0;
    node* last_node = 0;
    last_node_and_prev_node(&last_node, &prev_node);
    if(last_node == 0 || prev_node == 0){
        std::cout <<"list is empty"<< std::endl;
        return;
    }
    std::cout <<"get_end()"<< last_node->data << std::endl;
}

void list::pop_start(){
    if(head_node->next == head_node){
        std::cout << "List is empty" << std::endl;
        return;
    }
    std::cout <<"pop_start()"<< head_node->next->data << std::endl;
    generic_delete(head_node, head_node->next);

}

void list::pop_end(){ 
    if(head_node->next == head_node){
        std::cout << "List is empty" << std::endl;
        return;
    }
    node* prev_node = 0;
    node* last_node = 0;
    last_node_and_prev_node(&last_node, &prev_node);
    if(last_node == 0 || prev_node == 0){
        std::cout <<"list is empty"<< std::endl;
        return;
    }
    std::cout <<"pop_end()"<< last_node->data << std::endl;
    generic_delete(prev_node, last_node);
}

void list::remove_data(data_t e_data){
    node* prev_node = 0;
    node* current_node = 0;
    get_node_and_prev_node(e_data, &current_node, &prev_node);
    if(prev_node == 0 || current_node == 0){
        std::cout <<"Invalid data"<< std::endl;
        return;
    }
    generic_delete(prev_node, current_node);

}
void list::get_len(){
    node* run = 0;
    data_t len = 0;

    run = head_node->next;
    while(run != head_node){
        len += 1;
        run = run->next;
    }
    std::cout <<"Len = "<<len << std::endl;
}

void list::isEmpty(){
    if(head_node->next == 0){
        std::cout <<"List is empty" << std::endl;
        return;
    }
    std::cout <<"List is not empty"<< std::endl;

}
void list::generic_insert(node* prev, node* new_node){
    new_node->next = prev->next;
    prev->next = new_node;
}

void list::get_node_and_prev_node(data_t e_data, node** current_node , node** prev_node){
    node* start = 0;    
    node* end = 0;

    if(head_node->next != head_node){
        start = head_node;
        end = head_node->next;

        for(; end != head_node;){
            if(end->data == e_data)
                break;
            start = end;
            end = end->next;
        }
    }
    *current_node = end;
    *prev_node = start;
}

void list::last_node_and_prev_node(node** last_node, node** prev_node){
    node* start = 0;
    node* end = 0;
    
    if(head_node->next != head_node){
        start = head_node;
        end = head_node->next;

        for(; end->next != head_node;){
            start = end;
            end = end->next;
        }
    }
    *last_node = end;
    *prev_node = start;
}

void list:: generic_delete(node* prev_node, node* del_node){
    prev_node->next = del_node->next;
    delete del_node;
}

void list::show_list()
{
    node* run = 0;
    run = head_node->next;

    std::cout << "[START]" << std::endl;
    while(run != head_node)
    {
        std::cout <<"[" <<run->data <<"]"; 
        run = run->next;
    }
    std::cout << "[END]" << std::endl;
}