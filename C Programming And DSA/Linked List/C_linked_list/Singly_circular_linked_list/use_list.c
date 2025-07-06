#include "list.h"

int main(void){

    node_t* head_node = NULL;
    head_node = create_list();  
    insert_start(head_node, 10);
    show_list(head_node);
    insert_start(head_node, 20);
    show_list(head_node);
    insert_end(head_node, 30);
    show_list(head_node);
    insert_before(head_node, 10, 100);
    show_list(head_node);
    insert_after(head_node, 30, 200);
    show_list(head_node);
    get_start(head_node);
    show_list(head_node);
    get_end(head_node);
    show_list(head_node);
    pop_start(head_node);
    show_list(head_node);
    pop_end(head_node);
    show_list(head_node);
    remove_node(head_node, 20);
    show_list(head_node);
    get_len(head_node);
    show_list(head_node);
    destroy_list(&head_node);
    show_list(head_node);
    printf("Programe terminated succesfully");
    return EXIT_SUCCESS;
}
