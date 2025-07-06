#include "List.h"

/* Interface function   */
list_t* create_list(void){
    list_t* head_node = NULL;
    head_node = get_node(0);
    return head_node;
}

void insert_start(list_t* list, data_t new_data){
    generic_insert(list, get_node(new_data));
}

void insert_end(list_t* list, data_t new_data){
    node_t* last_node = NULL;
    node_t* prev_node = NULL;

    last_node_prev_node(list, &last_node, &prev_node); 
    generic_insert(last_node, get_node(new_data));
}

void insert_after(list_t* list, data_t e_data, data_t new_data){
    if(isEmpty(list) == TRUE){
        puts("List is empty");
        return;
    }
    node_t* current_node = NULL;
    node_t* prev_node = NULL;
    get_node_prev_node(list, e_data, &current_node, &prev_node);
    if(current_node == NULL){
        puts("Invalid data");
        return;
    }   
    generic_insert(current_node, get_node(new_data));
}

void insert_before(list_t* list, data_t e_data, data_t new_data){
    if(isEmpty(list) == TRUE){
        puts("List is empty");
        return;
    }
    node_t* current_node = NULL;    
    node_t* prev_node = NULL;
    get_node_prev_node(list, e_data, &current_node, &prev_node);
    if(current_node == NULL){
        puts("Invalid data");
        return;
    }
    generic_insert(prev_node, get_node(new_data));
}

void pop_start(list_t* list){
    if(isEmpty(list) == TRUE){
        puts("List is empty");
        return;
    }
    generic_delete(list, list->next);
}

void pop_end(list_t* list){
    if(isEmpty(list) == TRUE){
        puts("List is empty");
        return;
    }
    node_t* last_node = NULL;
    node_t* prev_node = NULL;
    last_node_prev_node(list, &last_node, &prev_node);
    generic_delete(prev_node, last_node);
}

void get_start(list_t* list){
    if(isEmpty(list) == TRUE){
        puts("List is empty");
        return;
    }
    printf("get_start(0 = %llu\n", list->next->data);
}

void get_end(list_t* list){
    if(isEmpty(list) == TRUE){
        puts("List is empty");
        return;
    }
    node_t* last_node = NULL;
    node_t* prev_node = NULL;
    last_node_prev_node(list, &last_node, &prev_node);
    printf("get_end() = %llu\n", last_node->data);
}

void remove_node(list_t* list, data_t e_data){
    if(isEmpty(list) == TRUE){
        puts("List is empty");
        return;
    }
    node_t* current_node = NULL;
    node_t* prev_node = NULL;
    get_node_prev_node(list, e_data, &current_node, &prev_node);
    if(current_node == NULL){
        puts("Invalid data");
        return;
    }
    generic_delete(prev_node, current_node);
}

status_t isEmpty(list_t* list){
    if(list->next == NULL)
        return TRUE; 
    return FALSE;
}
void get_len(list_t* list){
    data_t len = 0;
    node_t* run = list->next;
    for(; run != NULL; run = run->next){
        len+= 1;
    }
    printf("Length of list is = %llu\n", len);
}

void show(list_t* list){
    node_t* run = NULL;
    run = list->next;
    printf("[START]->");
    for(;run != NULL; run = run->next){
        printf("[%llu]", run->data);
    }
    puts("[END]");
}

void destroy_list(list_t** pp_list){
    node_t* head_node = NULL;
    head_node = *pp_list;
    node_t* run = NULL;
    node_t* run_next = NULL;

    for(run = head_node->next; run != NULL; run = run_next){
        run_next = run->next;
        free(run);
    }
    free(head_node);
    *pp_list = NULL;
}

list_t* concat(list_t* list1, list_t* list2){
    list_t* new_list = NULL;
    new_list = create_list();
    for(node_t* run = list1->next; run != NULL; run = run->next)
        insert_end(new_list, run->data);
    for(node_t* run = list2->next; run != NULL; run = run->next)
        insert_end(new_list, run->data);
    return new_list;
}
void append(list_t* list1, list_t* list2){
    if(list2->next != NULL){
        if(list1->next == NULL){
            list1->next = list2->next;
        }
        else
        {
            node_t* last_node = NULL;
            node_t* prev_node = NULL;
            last_node_prev_node(list1, &last_node, &prev_node);
            last_node->next = list2->next;
        }
    }
    free(list2);
}

list_t* merge(list_t* list1, list_t* list2){
    list_t* new_list = NULL;
    new_list = create_list();
    node_t* run1 = NULL;
    node_t* run2 = NULL;
    run1 = list1->next;
    run2 = list2->next;

    while(TRUE){
        if(run1 == NULL){
            for(node_t* run = list2->next; run!= NULL; run = run->next)
                insert_end(new_list, run->data);
            break;
        }
        else if(run2 == NULL){
            for(node_t* run = list1->next; run != NULL; run = run->next)
                insert_end(new_list, run->data);
            break;
        }
        else{
            if(run1->data < run2->data){
                insert_end(new_list, run1->data);
                run1 = run1->next;
            }
            else
            {
                insert_end(new_list, run2->data);
                run2 = run2->next;
            }
        }
    }
    return new_list;
}

void reverse_list(list_t* list1){
    if(list1->next == NULL || list1->next->next == NULL){
        return;
    }
    node_t* original_node = NULL;
    original_node = list1->next;
    node_t* run_next = NULL;
    for(node_t* run = list1->next->next; run != NULL; run = run_next){
        run_next = run->next;
        generic_insert(list1, run);
    }
    original_node->next = NULL;
}

/*  Helper function */
node_t* get_node(data_t new_data){
    node_t* p_node = NULL;
    p_node = xmalloc(sizeof(node_t));
    p_node->next = NULL;
    p_node->data = new_data;
    return p_node;
}

void* xmalloc(data_t new_required_byte){
    void* ptr = NULL;
    ptr = malloc(new_required_byte);
    assert(ptr != NULL);
    return ptr;
}

void get_node_prev_node(list_t* list, data_t e_data, node_t** current_node, node_t** prev_node){
    node_t* run = NULL;
    node_t* run_prev = NULL;
    if(list->next != NULL){
        run_prev = list;
        for(run = list->next; run != NULL; run = run->next){
            if(run->data == e_data)
                break;
            run_prev = run;
        }
    }
    *current_node = run;
    *prev_node = run_prev;
}

void last_node_prev_node(list_t* list, node_t** last_node, node_t** prev_node){
    node_t* run =  list;
    node_t* run_prev = NULL;
    if(list->next != NULL){
        for(run = list->next; run->next != NULL; run = run->next){
            run_prev = run;
        }
    }
    *last_node = run;
    *prev_node = run_prev;
}

/* Auxilary function    */
void generic_insert(node_t* start, node_t* new_node){
    new_node->next = start->next;
    start->next = new_node;
}

void generic_delete(node_t* prev_node, node_t* del_node){
    prev_node->next = del_node->next;
    free(del_node);
}