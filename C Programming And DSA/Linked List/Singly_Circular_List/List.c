#include "List.h"

/* Interface function  */
list_t* create_list(void){
    list_t* head_node = NULL;
    head_node = get_node(0);
    head_node->next = head_node;
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
        puts("Invalid list");
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
    get_node_prev_node(list,e_data, &current_node, &prev_node);
    if(current_node == NULL){
        puts("invalid data");
        return;
    }
    generic_insert(prev_node, get_node(new_data));
}

void get_start(list_t* list){
    if(isEmpty(list) == TRUE){
        puts("List is empty");
        return;
    }
    printf("get_start() = %llu\n", list->next->data);
}

void get_end(list_t* list){
    if(isEmpty(list) == TRUE){
        puts("List is empty");
        return;
    }
    node_t* prev_node = NULL;
    node_t* last_node = NULL;

    last_node_prev_node(list, &last_node, &prev_node);
    printf("get_end() = %llu\n", last_node->data);
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
    node_t* prev_node = NULL;
    node_t* last_node = NULL;

    last_node_prev_node(list, &last_node, &prev_node);
    generic_delete(prev_node, last_node);
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
    if(list->next == list)
        return TRUE;
    return FALSE;
}

void get_len(list_t* list){
    data_t len = 0;
    node_t* run = NULL;
    for(run = list->next; run != list; run = run->next){
        len+= 1;
    }       
    printf("length of list is = %llu\n", len);
}

void show(list_t* list){
    node_t* run = NULL;
    printf("[START]->");
    for(run = list->next; run != list; run = run->next){
        printf("[%llu]", run->data);
    }
    puts("[END]");
}

void destroy_list(list_t** pp_list){
    node_t* head_node = NULL;
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
        }
        else
        {       
            node_t* last_node = NULL;
            node_t* prev_node = NULL;
            last_node_prev_node(list1, &last_node, &prev_node);
            last_node->next = list2->next;
            last_node_prev_node(list2, &last_node, &prev_node);
            last_node->next = list1;
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
        generic_insert(list1, run);
    }
    original_node->next = list1;
}


/* Helper function  */
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

static void get_node_prev_node(list_t* list, data_t e_data, node_t** current_node, node_t** prev_node){
    node_t* run = NULL;
    node_t* run_prev = NULL;

    if(list->next != list){
        run_prev = list;
        for(run = list->next; run != list; run = run->next){
            if(run->data == e_data)
                break;
            run_prev = run;
        }
        if(run == list){
            run = NULL;
            run_prev = NULL;
			return;
        }
    }
    *current_node = run;
    *prev_node = run_prev;
}

static void last_node_prev_node(list_t* list, node_t** last_node, node_t** prev_node){
    node_t* run = NULL;
    node_t* run_prev = NULL;
    run = list;
    if(list->next != list){
        for(;run->next != list; run = run->next){
            run_prev = run;
        }
    }
    *last_node = run;
    *prev_node = run_prev;
}

/*  Auxilary function   */
static void generic_insert(node_t* start, node_t* new_node){
    new_node->next = start->next;
    start->next = new_node;
}

static void generic_delete(node_t* prev, node_t* del_node){
    prev->next = del_node->next;
    free(del_node);
}