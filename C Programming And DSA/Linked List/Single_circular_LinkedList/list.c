#include "list_header.h"

void destroy_list(node_list** head_node)
{
    node_list* run = NULL;
    node_list* run_prev =  NULL;

    run = (*head_node)->next;
    run_prev = (*head_node);
    while(run != (*head_node))
    {
        free(run_prev);
        run_prev = run;
        run = run->next;
    }
    *head_node = NULL;
    return;
}   
data_t list_length(node_list* head_node)
{
    node_list* run = NULL;
    data_t length = 0;
    run = head_node->next;
    while(run != head_node)
    {
        length += 1;
        run = run->next;
    }   
    return(length);
}
int insert_before(node_list* head_node, data_t e_data, data_t new_data)
{
    node_list* run = NULL;
    node_list* run_prev = NULL;
    node_list* p_new_node = NULL;
    run = head_node->next;
    run_prev = head_node;
    while(run != head_node)
    {
        if(run->data == e_data)
            break;

        run_prev = run;
        run = run->next;
    }

    p_new_node = get_node(new_data);
    p_new_node->next = run;
    run_prev->next = p_new_node;
    return(SUCESS);
}
int insert_after(node_list* head_node, data_t e_data, data_t new_data)
{
    node_list* run = NULL;
    run = head_node->next;
    while(run != head_node)
    {
        if(run->data == e_data)
            break;
    }

    generic_insert(run, get_node(new_data));
    return(SUCESS);
}
int remove_end(node_list* head_node)
{
    node_list* run = NULL;
    node_list* run_prev = NULL;

    run = head_node->next;
    run_prev = head_node;

    if(run == head_node)
        puts("Linked list is empty");

    while(run->next != head_node)
    {
        run_prev = run;
        run = run->next;
    }
    
    generic_delete(run_prev, run);
    return(SUCESS);
}
int remove_start(node_list* head_node)
{
    node_list* first_node = NULL;
    if(head_node->next == head_node)
        puts("List is empty");

    generic_delete(head_node, head_node->next);
    return(SUCESS);
}
int pop_end(node_list* head_node, data_t* last_data)
{
    node_list* run = NULL;
    node_list* run_prev = NULL;

    run = head_node->next;
    run_prev = head_node;

    if(run == head_node)
        return(INVALID_DATA);

    while(run->next != head_node)
    {
        run_prev = run;
        run = run->next;
    }
    *last_data = run->data;

    generic_delete(run_prev, run);  
    return(SUCESS);
}
void generic_delete(node_list* prev, node_list* r_node)
{
    prev->next = r_node->next;
    free(r_node);
    r_node = NULL;
}
int pop_start(node_list* head_node, data_t* first_data)
{
    node_list* first_node = NULL;
    
    if(head_node->next == head_node)
        puts("List is empty");

    first_node = head_node->next;
    *first_data = first_node->data;
    generic_delete(head_node, first_node);
    return(SUCESS);
}
int get_end(node_list* head_node, data_t* last_data)
{
    node_list* run = NULL;
    run = head_node->next;
    if(run == head_node)
        return(INVALID_DATA);

    while(run->next != head_node)
    {
        run = run->next;
    }
    *last_data = run->data;
    return(SUCESS);
}

int get_start(node_list* head_node, data_t* first_data)
{
    node_list* first_node = NULL;

    if(head_node->next == head_node)
        return(INVALID_DATA);
    first_node = head_node->next;
    *first_data = first_node->data;
    return(SUCESS);
}

void show_list(node_list* head_node)
{
    node_list* run = NULL;
    run = head_node->next;
    printf("[ENTER]");
    while(run != head_node)
    {
        printf("[%llu]", run->data);
        run = run->next;
    }
    printf("[END]\n");
}
node_list* find_last_node(node_list* head_node)
{
    node_list* run = NULL;
    run = head_node;
    while(run->next != head_node)
    {
        run = run->next;
    }
    return(run);
}
void insert_end(node_list* head_node, data_t new_data)
{
    node_list* last_node = NULL;
    last_node = find_last_node(head_node);
    generic_insert(last_node, get_node(new_data)); 
}
void insert_start(node_list* head_node, data_t new_data)
{
    generic_insert(head_node, get_node(new_data));
}
static void generic_insert(node_list* prev, node_list* mid)
{
    mid->next = prev->next;
    prev->next = mid;
}

node_list* create_list()
{
    node_list* head_node = NULL;
    head_node = get_node(0);
    head_node->next = head_node;
    return(head_node);
}

static node_list* get_node(data_t new_data)
{
    node_list* p_new_node = NULL;
    p_new_node = (node_list*)xmalloc(sizeof(node_list));
    p_new_node->next = NULL;
    p_new_node->data = new_data;
    return(p_new_node);
}
static void* xmalloc(data_t data)
{
    void* ptr = NULL;
    ptr = malloc(data);
    assert(ptr != NULL);
    return(ptr);
}
