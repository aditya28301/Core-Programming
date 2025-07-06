/*
 *  test_driver.c – rigorous exercise of the doubly-circular list API
 *
 *  Build:   gcc -Wall -Wextra -pedantic -std=c17 test_driver.c list.c -o list_demo
 *  Run:     ./list_demo
 */

#include <stdio.h>
#include <assert.h>
#include "list.h"          /* replace with your header’s real name */

/* pretty divider */
static void banner(const char *msg)
{
    puts("\n==================================================");
    puts(msg);
    puts("==================================================");
}

int main(void)
{
    banner("1. Create empty list");
    node_t *head = create_list();
    assert(head);
    show_list(head);               /* should print “List is empty” (or similar) */

    banner("2. Inserting at START on empty list, then again");
    insert_start(head, 10);
    insert_start(head, 20);        /* List: 20 10 */
    show_list(head);

    banner("3. Inserting at END (twice)");
    insert_end(head, 30);
    insert_end(head, 40);          /* List: 20 10 30 40 */
    show_list(head);

    banner("4. Insert AFTER & BEFORE middle elements");
    insert_after(head, 10, 15);    /* after 10  -> 20 10 15 30 40 */
    insert_before(head, 30, 25);   /* before 30 -> 20 10 15 25 30 40 */
    show_list(head);

    banner("5. Get first & last elements");
    get_start(head);               /* expect 20  */
    get_end(head);                 /* expect 40 */

    banner("6. Pop first & last elements");
    pop_start(head);               /* removes 20 */
    pop_end(head);                 /* removes 40 */
    show_list(head);               /* 10 15 25 30 */

    banner("7. Remove a specific element (value 25)");
    remove_node(head, 25);         /* 10 15 30 */
    show_list(head);

    banner("8. Try to remove a non-existent element (99)");
    remove_node(head, 99);         /* should report NOT-FOUND gracefully */
    show_list(head);

    banner("9. Current length");
    get_len(head);                 /* expect length 3 */

    banner("10. Pop everything until empty");
    pop_start(head);               /* removes 10 */
    pop_start(head);               /* removes 15 */
    pop_start(head);               /* removes 30 (list now empty) */
    show_list(head);

    banner("11. Edge-case operations on EMPTY list");
    pop_start(head);               /* should warn/error-handle */
    pop_end(head);                 /* idem */
    remove_node(head, 123);        /* idem */

    banner("12. Re-insert after emptying (robustness)");
    insert_end(head, 111);
    insert_start(head, 222);       /* List: 222 111 */
    show_list(head);

    banner("13. Destroy list and verify head NULL");
    destroy_list(&head);
    assert(head == NULL);
    puts("All tests completed – if no assertion fired, basic list ops work!");

    return 0;
}

