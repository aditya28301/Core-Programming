#include "singly_circular_list.hpp"

int main() {
    list myList;

    // Test: Insert at start
    myList.insert_start(10);
    myList.insert_start(20);
    myList.insert_start(30);
    myList.show_list();  // Expected: [30]->[20]->[10]->[END]

    // Test: Insert at end
    myList.insert_end(40);
    myList.insert_end(50);
    myList.show_list();  // Expected: [30]->[20]->[10]->[40]->[50]->[END]

    // Test: Insert after
    myList.insert_after(20, 25);
    myList.show_list();  // Expected: [30]->[20]->[25]->[10]->[40]->[50]->[END]

    // Test: Insert before
    myList.insert_before(10, 5);
    myList.show_list();  // Expected: [30]->[20]->[25]->[5]->[10]->[40]->[50]->[END]

    // Test: Get start and end
    myList.get_start();  // Expected: 30
    myList.get_end();    // Expected: 50
    myList.show_list();

    // Test: Delete start
    myList.pop_start();
    myList.show_list();  // Expected: [20]->[25]->[5]->[10]->[40]->[50]->[END]

    // Test: Delete end
    myList.pop_end();
    myList.show_list();  // Expected: [20]->[25]->[5]->[10]->[40]->[END]

    // Test: Remove specific data
    myList.remove_data(25);
    myList.show_list();  // Expected: [20]->[5]->[10]->[40]->[END]

    // Test: Get list length
    myList.get_len();    // Expected: Len = 4

    // Test: Check if list is empty
    myList.isEmpty();    // Expected: List is not empty
    std::cout <<"Program terminated sucessfully" << std::endl;
    return 0;
}
