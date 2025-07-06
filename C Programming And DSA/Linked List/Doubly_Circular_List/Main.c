#include "List.h"
#include <stdio.h>
#include <stdlib.h>

/* Function to rigorously test the linked list */
int main(void) {
    // Create list
    list_t* my_list = create_list();
    printf("List created.\n");
    
    // Check if the list is initially empty
    if (isEmpty(my_list)) {
        printf("List is initially empty.\n");
    } else {
        printf("Error: List should be empty.\n");
    }

    // Insert elements at the start
    insert_start(my_list, 30);
    insert_start(my_list, 20);
    insert_start(my_list, 10);
    printf("After inserting 30, 20, 10 at start:\n");
    show(my_list);  // Expected: [START]->[30][20][10][END]

    // Insert elements at the end
    insert_end(my_list, 50);
    insert_end(my_list, 60);
    printf("After inserting 40, 50 at end:\n");
    show(my_list);  // Expected: [START]->[30][20][10][40][50][END]

    // Insert an element after a node
    insert_after(my_list, 20, 25);
    printf("After inserting 25 after 20:\n");
    show(my_list);  // Expected: [START]->[30][20][25][10][40][50][END]

    // Insert an element before a node
    insert_before(my_list, 50, 45);
    printf("After inserting 35 before 40:\n");
    show(my_list);  // Expected: [START]->[30][20][25][10][35][40][50][END]

    // Pop (delete) the first element
    pop_start(my_list);
    printf("After popping the first element:\n");
    show(my_list);  // Expected: [START]->[20][25][10][35][40][50][END]

    // Pop (delete) the last element
    pop_end(my_list);
    printf("After popping the last element:\n");
    show(my_list);  // Expected: [START]->[20][25][10][35][40][END]

    // Remove a specific node
    remove_node(my_list, 50);
    printf("After removing the node with value 35:\n");
    show(my_list);  // Expected: [START]->[20][25][10][40][END]

    // Get the value of the first and last elements
    get_start(my_list);  // Expected: 20
    get_end(my_list);    // Expected: 40

    // Get the length of the list
    get_len(my_list);    // Expected: 4

    /* Concatination of linked list */
    list_t* list2 = NULL;
    list_t* concat_list = NULL;

    list2 = create_list();
    insert_start(list2, 300);
    insert_start(list2, 200);
    insert_start(list2, 100);
    printf("After inserting 30, 20, 10 at start:\n");
    puts("Show() = list1 & list2");
    show(my_list);
    show(list2);
    puts("Concatination of list");
    concat_list = concat(my_list, list2);
    show(concat_list);
    
    /* Merge List   */
    puts("Merge List");
    list_t* merge_list = NULL;
    merge_list = merge(my_list, list2);
    show(merge_list);

    /* Append list  */
    puts("Append List");
    append(my_list, list2);
    show(my_list);

    /* Reverse List */
    puts("Reverse List");
    reverse_list(my_list);
    show(my_list);

    // Clean up and destroy the list
    destroy_list(&my_list);
    printf("List destroyed");

    return 0;
}
