#include "list_header.h"

int main(void)
{
    data_t first_data;
    data_t last_data;
    data_t length;
    int status;
    node_list* head_node = NULL;
    head_node = create_list();

    insert_start(head_node, 10);
    insert_end(head_node, 20);
    insert_end(head_node, 30);
    insert_end(head_node, 40);
    insert_end(head_node, 50);
    insert_start(head_node, 60);
    // insert_start(head_node, 40);

    show_list(head_node);
    status = get_start(head_node, &first_data);
    if(status == INVALID_DATA)
        puts("List is empty");
    else    
        printf("First node data = [%llu]\n", first_data);
    status = get_end(head_node, &last_data);
    if(status == INVALID_DATA)
        puts("puts List is empty");
    else    
        printf("Last node data is = [%llu]\n", last_data);

    status = pop_start(head_node, &first_data);
    if(status == INVALID_DATA)
        puts("List is empty");
    else
        printf("first node data = [%llu] is deleted\n", first_data);

    status = pop_end(head_node, &last_data);
    if(status == INVALID_DATA)
        puts("List is empty");
    else
        printf("pop_end() data = [%llu]\n", last_data);\

    status = remove_start(head_node);
    if(status == INVALID_DATA)
        puts("List is empty");
    else
        puts("starting Node deleted");

    status = remove_end(head_node);
    if(status == INVALID_DATA)
        puts("List is empty");
    else        
        puts("ending node are deleted");

    status = insert_after(head_node, 20, 100);
    if(status == INVALID_DATA)
        puts("List is empty");
    else
        printf("insert_after() done sucessfully");

    status = insert_before(head_node, 100, 50);
    if(status == INVALID_DATA)
        puts("List is empty");
        else
        puts("data inserted before");

    show_list(head_node);

    length = list_length(head_node);
    printf("Length of list is = [%llu]\n", length);

    destroy_list(&  head_node);
    puts("ALL node are destory sucessfully");
    show_list(head_node);
    return (0);
}
