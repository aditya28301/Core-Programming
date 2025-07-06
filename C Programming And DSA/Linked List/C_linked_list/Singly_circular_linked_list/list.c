#include "list.h"

static void generic_insert(node_t* prev_node, node_t* new_node, node_t* next_node){

    new_node->next = next_node;
    prev_node->next = new_node;
}

static void get_prev_node_current_node(node_t* head_node, node_t** prev_node, node_t** current_node, data_t e_data){
    // puts("called get prev");
    node_t* run_current = NULL;
    node_t* run_prev = NULL;

    if(head_node->next != head_node){
        
        run_current = head_node->next;
        run_prev = head_node;

        while(run_current != head_node){
            if(run_current->data == e_data){
                *prev_node = run_prev;
                *current_node = run_current;
                puts("end get prev");
                return;
            }

            run_prev = run_current;
            run_current = run_current->next;
        }
    }
            *prev_node = NULL;
            *current_node = NULL;
  
    return;
    // puts("end get prev");
}

void* xmalloc(data_t new_required_byte){
    void* ptr = NULL;
    ptr = malloc(new_required_byte);
    if(ptr == NULL){
        puts("Error in allocating the meomary");
        exit(EXIT_FAILURE);
    }
    return (ptr);
}

node_t* get_node(data_t new_data){ 
    node_t* new_node = NULL;
    new_node = (node_t*)xmalloc(sizeof(node_t));
    new_node->next = NULL;
    new_node->data = new_data;
    return (new_node);
}

node_t* create_list(){
    node_t* head_node = NULL;
    head_node = get_node(0);
    head_node->next = head_node;
    return head_node;
}

void insert_start(node_t* head_node, data_t new_data){
    generic_insert(head_node, get_node(new_data), head_node->next);
}

void insert_end(node_t* head_node, data_t new_data)
{
    puts("called insert_end()");
    node_t* run = NULL;
    node_t* new_node = NULL;

    run = head_node->next;
    
    while(run->next != head_node){
        run = run->next;
    }

    new_node = get_node(new_data);
    new_node->next = run->next;
    run->next = new_node;
    // puts("end insert_end()");
}

void insert_before(node_t* head_node, data_t e_data, data_t new_data){
    // puts("called insert_before");
    node_t* prev_node = NULL;
    node_t* current_node = NULL;
    node_t* new_node = NULL;

    get_prev_node_current_node(head_node, &prev_node, &current_node, e_data);
    if(prev_node == head_node && current_node == head_node){
        puts("INVALID DATA");
        return;
    }

    generic_insert(prev_node, get_node(new_data), current_node);
    // puts("end insert_before");
}

void insert_after(node_t* head_node, data_t e_data, data_t new_data){
    // puts("called insert_after");
    node_t* prev_node = NULL;
    node_t* current_node = NULL;
    node_t* new_node = NULL;

    get_prev_node_current_node(head_node, &prev_node, &current_node, e_data);
    if(prev_node == NULL && current_node == NULL){
        puts("INVALID DATA");
        puts("end insert_after");
        return;
    }
    generic_insert(current_node, get_node(new_data), current_node->next);
    // puts("end insert_after");
}

void get_start(node_t* head_node){
    // puts("called get_start");
    if(head_node->next == head_node){
        puts("LIST IS EMPTY");
        return;
    }   

    printf("Get_start() = %llu\n", head_node->next->data);
    // puts("end get_start()");
}

void get_end(node_t* head_node){
    // puts("get_end()");
    if(head_node->next == head_node){
        puts("LIST IS EMPTY");
        return;
    }

    node_t* run = NULL;

    run = head_node;
    while(run->next != head_node){
        run = run->next;
    }

    printf("get_end() data is = %llu\n", run->data);
    // puts("get_end()");
}



void pop_start(node_t* head_node){
    // puts("called pop_end()");
    if(head_node->next == head_node){
        puts("LIST IS EMPTY");
        return;
    }

    printf("pop_start() = %llu\n", head_node->next->data);
    
    node_t* del_node = head_node->next;
    head_node->next = del_node->next;

    free(del_node);
    // puts("end pop_end()");
}

void pop_end(node_t* head_node){
    // puts("called pop_end()");
    if(head_node->next == head_node){
        puts("LIST IS EMPTY");
        return;
    }

    node_t* run_prev = NULL;
    node_t* run_next = NULL;

    run_prev = head_node;
    run_next = head_node->next;

    while(run_next->next != head_node){
    
        run_prev = run_next;
        run_next = run_next->next;
    }

    run_prev->next = run_next->next;
    free(run_next);

    // puts("end pop_end()");
}

void remove_node(node_t* head_node, data_t d_data){
    // puts("called remove_node()");
    node_t* run = NULL;
    run = head_node->next;

    node_t* prev_node = NULL;
    node_t* next_node = NULL;

    get_prev_node_current_node(head_node, &prev_node, &next_node, d_data);
    if(next_node == NULL && prev_node == NULL){
        puts("INVALID_DATA");
        return;
    }

    prev_node->next = next_node->next;
    free(next_node);
    // puts("end remove_node()");
}

void get_len(node_t* head_node){
    // puts("called get_len()");
    node_t* run = head_node->next;
    data_t len = 0;
    while(run != head_node){
        len = len + 1;
        run = run->next;
    }
    
    printf("Length of linked list is = %llu\n", len);
    // puts("end get_len()");
}

void show_list(node_t* head_node){
    // puts("called show_list()");

    printf("[START]->");
    if(head_node != NULL){
        node_t* run = head_node->next;
        while(run != head_node){
            printf("[%llu]->", run->data);
            run = run->next;
        }
    }
    printf("[END]\n");
    // puts("end show_list()");
}

void destroy_list(node_t** p_head_node){
    // puts("called destroy_list()");
    node_t* head_node = NULL;
    head_node = *p_head_node;
    node_t* run = head_node->next;
    node_t* run_next = NULL;
    
    while(run != head_node){
        run_next = run->next;
        free(run);
        run = run_next;
    }

    free(head_node);
    *p_head_node = NULL;
    // puts("end destroy_list()");
}