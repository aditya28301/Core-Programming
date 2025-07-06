#include "list.hpp"

int main() {
    list my_list;

    // Test insertion at the start
    my_list.insert_start(10);
    my_list.insert_start(20);
    my_list.insert_start(30);
    std::cout << "List after inserting at the start: ";
    my_list.show();

    // Test insertion at the end
    my_list.insert_end(40);
    my_list.insert_end(50);
    std::cout << "List after inserting at the end: ";
    my_list.show();

    // Test insertion after a specific node
    my_list.insert_after(20, 25);
    std::cout << "List after inserting 25 after 20: ";
    my_list.show();

    // Test insertion before a specific node
    my_list.insert_before(25, 22);
    std::cout << "List after inserting 22 before 25: ";
    my_list.show();

    // Test removing the start node
    my_list.pop_start();
    std::cout << "List after popping the start node: ";
    my_list.show();

    // Test removing the end node
    my_list.pop_end();
    std::cout << "List after popping the end node: ";
    my_list.show();

    // Test removing a specific node
    my_list.remove_node(22);
    std::cout << "List after removing node with data 22: ";
    my_list.show();

    // Test getting the start and end data
    my_list.get_start();
    my_list.get_end();

    // Test length of the list
    my_list.get_len();

    // Test if the list is empty
    if (my_list.isEmpty() == TRUE) {
        std::cout << "The list is empty." << std::endl;
    } else {
        std::cout << "The list is not empty." << std::endl;
    }

    // Test destructor by going out of scope
    std::cout <<"Program terminated sucesfully" << std::endl;
    return 0;
}
