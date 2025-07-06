    /* Header file declearation */
    #include <stdio.h>
    #include <stdlib.h>
    #include <assert.h>

    /*Symbolic constant */
    #define TRUE    1
    #define FALSE   2

    /*Typedefination */
    typedef unsigned long long int data_t;
    typedef int status_t;
    typedef struct node node_t;
    typedef node_t list_t;

    /* Structure decleration    */
    struct node{
        data_t data;
        struct node* next;  
        struct node* prev;
    };

    /* Interface function   */
    list_t* create_list(void);
    void insert_start(list_t* list, data_t new_data);
    void insert_end(list_t* list, data_t new_data);
    void insert_after(list_t* list, data_t e_data, data_t new_data);
    void insert_before(list_t* list, data_t e_data, data_t new_data);
    void get_start(list_t* list);
    void get_end(list_t* list);
    void pop_start(list_t* list);
    void pop_end(list_t* list);
    void remove_node(list_t* list, data_t e_data);
    status_t isEmpty(list_t* list);
    void get_len(list_t* list);
    void show(list_t* list);
    void destroy_list(list_t** pp_list);
    list_t* concat(list_t* list1, list_t* list2);
    void append(list_t* list1, list_t* list2);
    list_t* merge(list_t* list1, list_t* list2);
    void reverse_list(list_t* list1);

    /* Helper function */
    node_t* get_node(data_t new_data);
    void* xmalloc(data_t new_required_byte);

    /* Auxilairy function   */
    static void generic_insert(node_t* start, node_t* new_node, node_t* end);
    static void generic_delete(node_t* del_node);
    static node_t* search_node(list_t* list, data_t e_data);