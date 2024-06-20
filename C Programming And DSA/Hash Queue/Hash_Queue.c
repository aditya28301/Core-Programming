#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>

#define TRUE    1 
#define FALSE   0
#define SUCCESS 1 
 
typedef unsigned long long int key_t; 
typedef unsigned long long int index_t; 

typedef struct hash_queue hash_queue_t; 
typedef struct node node_t; 
typedef node_t list_t; 

typedef int status_t; 

struct node{
    key_t key; 
    struct node* prev; 
    struct node* next; 
}; 

struct hash_queue{
    list_t* p_list_head_array; 
    size_t bucket_size; 
}; 

/* Hash queue interface functions */
hash_queue_t** create_hash_queue(size_t bucket_size); 
void add_key(hash_queue_t** p_hash_queue, key_t key); 
//status_t remove_key(hash_queue_t* p_hash_queue, key_t key); 
status_t search_key(hash_queue_t* p_hash_queue, key_t key); 
void show_hash_queue(hash_queue_t** p_hash_queue); 
status_t destroy_hash_queue(hash_queue_t*** p_hash_queue); 

/* Hash queue helper function */
static index_t hash(key_t key, size_t bucket_size);

/* Linked list interface functions */
list_t* create_list(void); 
status_t insert_end(list_t* p_list, key_t key); 
status_t remove_key(list_t* p_list, key_t key); 
status_t find(list_t* p_list, key_t key); 

/* Linked list helper functions */
static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end); 
static void generic_delete(node_t* p_delete_node); 
static node_t* search_node(list_t* p_list, key_t key); 
static node_t* get_node(key_t key); 
static void* xmalloc(size_t size_in_bytes);
void show_list(list_t* p_node); 
void destroy(list_t* l);

int main(void){

    size_t bucket_size = 5;
    int status;

    hash_queue_t** pp_hash_q =  create_hash_queue(bucket_size);
    add_key(pp_hash_q, 10);
    add_key(pp_hash_q, 19);
    add_key(pp_hash_q, 27);
    add_key(pp_hash_q, 37);
    
    show_hash_queue(pp_hash_q);
    status = destroy_hash_queue(&pp_hash_q);
    assert(status != EXIT_FAILURE);
    if(pp_hash_q == NULL)
        puts("Executed success");

    return  (EXIT_SUCCESS);  
}

/* Hash queue interface functions */
hash_queue_t** create_hash_queue(size_t bucket_size){
    size_t i;
    hash_queue_t** aHash_q = NULL;
    aHash_q = (hash_queue_t**)malloc((bucket_size) * sizeof(hash_queue_t*));

    if (aHash_q == NULL) {
        perror("Failed to allocate memory for hash queue array");
        return NULL;
    }

    for(i = 0; i < bucket_size; ++i){
        aHash_q[i] = (hash_queue_t*)malloc(sizeof(hash_queue_t));
        if (aHash_q[i] == NULL) {
            perror("Failed to allocate memory for hash queue");
            return NULL;
            for(size_t j = 0; j < i; ++j) {
                free(aHash_q[j]);
            }
        }
        aHash_q[i]->p_list_head_array = create_list();
        if (aHash_q[i]->p_list_head_array == NULL) {
            puts("Failed to create list");
            return NULL;
        }
        if(aHash_q[i]->p_list_head_array == NULL){
            puts("null occured");
        }
        aHash_q[i]->bucket_size = bucket_size;
    }
    return aHash_q;
}

void add_key(hash_queue_t** p_hash_queue, key_t key){
    size_t bucket_size;
    size_t index;

    bucket_size = (*p_hash_queue)[0].bucket_size;
    index = hash(key,bucket_size);
    list_t* head_node = NULL;

    head_node = p_hash_queue[index]->p_list_head_array;
    insert_end(head_node, key);
    return;
}

// status_t remove_key(hash_queue_t* p_hash_queue, key_t key){

// }

// status_t search_key(hash_queue_t* p_hash_queue, key_t key){

// }

void show_hash_queue(hash_queue_t** p_hash_queue){

    puts("printing all hash queue");
    for(size_t i =0; i < p_hash_queue[0]->bucket_size; ++i){
        printf("Queue = %llu\n", i);
        if(p_hash_queue[i]->p_list_head_array == NULL)
            assert(p_hash_queue[i]->p_list_head_array != NULL);

        show_list(p_hash_queue[i]->p_list_head_array);
    }
}

status_t destroy_hash_queue(hash_queue_t*** p_hash_queue){
    size_t b = ((*p_hash_queue)[0])->bucket_size;

    for(size_t i = 0; i < b; ++i){
        list_t* dhash_q = NULL;
        dhash_q = ((*p_hash_queue)[i])->p_list_head_array;
        destroy(dhash_q);
        ((*p_hash_queue)[i]) = NULL;
    }
        free((*p_hash_queue));
        *p_hash_queue = NULL;
    return(EXIT_SUCCESS);
}

void destroy(list_t* l){
    list_t* run = NULL;
    list_t* run_prev = NULL;

    run = l;
    while(run != l){

        run_prev = run;
        run = run->next;
        free(run_prev);
        run_prev = NULL;
    }
}
/* Linked list interface functions */
list_t* create_list(void){

    list_t* p_node = NULL;
    p_node = get_node(0);
    assert(p_node!=NULL);
    return p_node;
}

status_t insert_end(list_t* p_list, key_t key){
  if (p_list == NULL) {
        fprintf(stderr, "Error: List is NULL\n");
        return FALSE;
    }

    node_t* new_node = get_node(key);
    if (new_node == NULL) {
        fprintf(stderr, "Error: Failed to create new node\n");
        return FALSE;
    }
    generic_insert(p_list->prev, get_node(key), p_list);
    return(SUCCESS);
}

// status_t remove_key(list_t* p_list, key_t key){

// }

// status_t find(list_t* p_list, key_t key){

// }

/* Linked list helper functions */
static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end){

    if (p_beg == NULL || p_mid == NULL || p_end == NULL) {
        puts("Invalid nodes for insertion");
        return;
    }
    p_mid->prev = p_beg;
    p_mid->next = p_end;
    p_beg->next = p_mid;
    p_end->prev = p_mid;
}

// static void generic_delete(node_t* p_delete_node){

// }

// static node_t* search_node(list_t* p_list, key_t key){

// }

static node_t* get_node(key_t key){

    node_t* p_node = NULL;
    p_node = (node_t*)xmalloc(sizeof(node_t));
    if (p_node == NULL) {
        perror("Failed to allocate memory for node");
        return NULL;
    }
    p_node->key = key;
    p_node->next = p_node;
    p_node->prev = p_node;
    return (p_node);
}

static void* xmalloc(size_t size_in_bytes){

    void* dMem = NULL;
    dMem = malloc(size_in_bytes);
    assert(dMem != NULL);
    return dMem;
}

static index_t hash(key_t key, size_t bucket_size){
    return (key % bucket_size); 
}

void show_list(list_t* p_node){
    list_t* run = NULL;

    if(p_node == NULL)
        puts("NULL");

    run = p_node->next;
    printf("[head_node]->");
    while(run != p_node){
        printf("[%llu]->", run->key);
        run = run->next;
    }
    puts("[END]\n");
}