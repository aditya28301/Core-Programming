#include <stdio.h>
#include "list.h"

int main() {
    node_t* head = create_list();

    printf("\n--- Inserting at start ---\n");
    printf("insert_start(head, 10)\n");
    insert_start(head, 10);
    show_list(head);

    printf("\ninsert_start(head, 20)\n");
    insert_start(head, 20);
    show_list(head);

    printf("\ninsert_start(head, 30)\n");
    insert_start(head, 30);
    show_list(head);

    printf("\n--- Inserting at end ---\n");
    printf("insert_end(head, 40)\n");
    insert_end(head, 40);
    show_list(head);

    printf("\ninsert_end(head, 50)\n");
    insert_end(head, 50);
    show_list(head);

    printf("\n--- Insert after existing node ---\n");
    printf("insert_after(head, 40, 45) // After 40, insert 45\n");
    insert_after(head, 40, 45);
    show_list(head);

    printf("\n--- Insert before existing node ---\n");
    printf("insert_before(head, 10, 5) // Before 10, insert 5\n");
    insert_before(head, 10, 5);
    show_list(head);

    printf("\n--- Get Start ---\n");
    get_start(head);

    printf("\n--- Get End ---\n");
    get_end(head);

    printf("\n--- Get Length ---\n");
    get_len(head);

    printf("\n--- Pop Start ---\n");
    pop_start(head);
    show_list(head);

    printf("\n--- Pop End ---\n");
    pop_end(head);
    show_list(head);

    printf("\n--- Remove specific node ---\n");
    printf("remove_node(head, 45)\n");
    remove_node(head, 45);
    show_list(head);

    printf("\n--- Final List ---\n");
    show_list(head);

    printf("\n--- Destroying List ---\n");
    destroy_list(&head);

    if (head == NULL)
        printf("List destroyed successfully.\n");
	show_list(head);
	printf("\n");
	puts("programe termianted succesuflly");
    return 0;
}

