#include "List.h"

/* Interface function   */
list_t* create_list(void){
    list_t* head_node = NULL;
    head_node = get_node(0);
    head_node->next = head_node;
    head_node->prev = head_node;
    return head_node;
}

void insert_start(list_t* list, data_t new_data){
   generic_insert(list, get_node(new_data), list->next);
}
void insert_end(list_t* list, data_t new_data){
    generic_insert(list->prev, get_node(new_data), list);
}

void insert_after(list_t* list, data_t e_data, data_t new_data){
    node_t* e_node = NULL;  
    e_node = search_node(list, e_data);
    if(e_node == NULL){
        puts("Invalid data");
        return;
    }
    generic_insert(e_node, get_node(new_data), e_node->next);
}

void insert_before(list_t* list, data_t e_data, data_t new_data){
   node_t* e_node = NULL;  
    e_node = search_node(list, e_data);
    if(e_node == NULL){
        puts("Invalid data_1");
        return;
    }
    generic_insert(e_node->prev, get_node(new_data), e_node);
}

void get_start(list_t* list){
     if(isEmpty(list) == TRUE){
        puts("List is empty");
        return;
    }
    printf("get_start() = %llu", list->next->data);
}

void get_end(list_t* list){
    if(isEmpty(list) == TRUE){
        puts("List is empty");
        return;
    }
    printf("get_end() = %llu", list->prev->data);
}

void pop_start(list_t* list){
    if(isEmpty(list) == TRUE){
        puts("List is empty");
        return;
    }
    generic_delete(list->next);
}

void pop_end(list_t* list){
    if(isEmpty(list) == TRUE){
        puts("List is empty");
        return;
    }
    generic_delete(list->prev);
}

void remove_node(list_t* list, data_t e_data){
    node_t* e_node = NULL;  
    e_node = search_node(list, e_data);
    if(e_node == NULL){
        puts("Invalid data");
        return;
    }
    generic_delete(e_node);
}

status_t isEmpty(list_t* list){
    if(list->next == list && list->prev == list)
        return TRUE;
    return FALSE;
}

void get_len(list_t* list){
    data_t len = 0;
    node_t* run = NULL;
    for(run = list->next; run != list; run = run->next){
        len+= 1;
    }
    printf("List length is = %llu\n", len);
}

void show(list_t* list){
    node_t* run = NULL;
    printf("[START]");
    for(run = list->next; run != list; run = run->next){
        printf("[%llu]", run->data);
    }
    printf("[END]\n");
}

void destroy_list(list_t** pp_list){
    list_t* head_node = NULL;
    head_node = *pp_list;
    node_t* run = NULL;
    node_t* run_next = NULL;
    for(run = head_node->next; run != head_node; run = run_next){
        run_next = run->next;
        free(run);
    }
    free(head_node);
    *pp_list = NULL;
}

list_t* concat(list_t* list1, list_t* list2){
    list_t* new_list = NULL;
    new_list = create_list();
    for(node_t* run = list1->next; run != list1; run = run->next)
        insert_end(new_list, run->data);
    for(node_t* run = list2->next; run != list2; run = run->next)
        insert_end(new_list, run->data);    
    return new_list;
}

void append(list_t* list1, list_t* list2){
    if(list2->next != list2){
        if(list1->next == list1){
            list1->next = list2->next;
            list2->next->prev = list1;
        }
        else
        {       
            list1->prev->next = list2->next;
            list2->next->prev = list1->prev;
            list2->prev->next = list1;
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
        if(run1 == list1){
            for(node_t* run = list2->next; run!= list2; run = run->next){
                insert_end(new_list, run->data);
            }
            break;
        }
        else if(run2 == list2){
            for(node_t* run = list1->next; run != NULL; run = run->next){
                insert_end(new_list, run->data);
            }
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
            show(new_list);
        }
    }
    return new_list;
}

void reverse_list(list_t* list1){
    if(list1->next == list1 || list1->next->next == list1){
        return;
    }
    node_t* original_node = NULL;
    original_node = list1->next;
    node_t* run_next = NULL;
    for(node_t* run = list1->next->next; run != list1; run = run_next){
        run_next = run->next;
        generic_insert(list1, run, list1->next);
    }
    original_node->next = list1;
}

/* Helper function */
node_t* get_node(data_t new_data){
    node_t* p_node = NULL;
    p_node = (node_t*)xmalloc(sizeof(node_t));
    p_node->next = NULL;
    p_node->prev = NULL;    
    p_node->data = new_data;
    return p_node;
}

void* xmalloc(data_t new_required_byte){
    void* ptr = NULL;
    ptr = malloc(new_required_byte);
    assert(ptr != NULL);
    return ptr;
}


/* Auxilairy function   */
static void generic_insert(node_t* start, node_t* new_node, node_t* end){
    new_node->next = end;
    new_node->prev = start;
    start->next = new_node;
    end->prev = new_node;
}
static void generic_delete(node_t* del_node){
    node_t* start = NULL;
    node_t* end = NULL;

    start = del_node->prev;
    end = del_node->next;

    start->next = end;
    end->prev = start;
    free(del_node);
}
static node_t* search_node(list_t* list, data_t e_data){
    node_t* run = NULL;
    for(run = list->next; run != list; run = run->next){
        if(run->data == e_data)
            return run;
    }
    return NULL;
}