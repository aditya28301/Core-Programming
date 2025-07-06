#include "list.hpp"


int main(void){

    node_t* head_node = NULL;
    head_node = create_list();
    insert_start(head_node, 10);
    insert_end(head_node, 20);
    insert_end(head_node, 30);
    insert_end(head_node, 40);
    insert_before(head_node, 10, 100);
    insert_after(head_node, 20, 200);
    get_start(head_node);
    get_end(head_node);
    show_list(head_node);
    pop_start(head_node);
    pop_end(head_node);
    show_list(head_node);
    remove_node(head_node, 30);
    isEmpty(head_node);
    get_len(head_node);
    find(head_node, 200);
    show_list(head_node);
    destroy_list(&head_node);
    show_list(head_node);
    printf("Program terminated succesfully");
    return EXIT_SUCCESS;
}