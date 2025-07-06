#include <iostream>
#include "singly_list.hpp"

void testListOperations() {
    list myList;

    std::cout << "Testing insertion at start:" << std::endl;
    myList.insert_start(10);
    myList.insert_start(20);
    myList.insert_start(30);

    std::cout << "Testing get_start:" << std::endl;
    myList.get_start();  // Expected output: 30

    std::cout << "Testing insertion at end:" << std::endl;
    myList.insert_end(40);
    myList.insert_end(50);

    std::cout << "Testing get_end:" << std::endl;
    myList.get_end();  // Expected output: 50

    std::cout << "Testing insertion after 20:" << std::endl;
    myList.insert_after(20, 25);

    std::cout << "Testing insertion before 40:" << std::endl;
    myList.insert_before(40, 35);

    std::cout << "Testing find 25:" << std::endl;
    myList.find(25);  // Expected output: Data is present in the list

    std::cout << "Testing find 100:" << std::endl;
    myList.find(100);  // Expected output: Data is not present in the list

    std::cout << "Testing get_len:" << std::endl;
    myList.get_len();  // Expected output: Len = 7 (or the number of nodes in the list)

    std::cout << "Testing pop_start:" << std::endl;
    myList.pop_start();  // Expected output: 30

    std::cout << "Testing get_start after pop_start:" << std::endl;
    myList.get_start();  // Expected output: 20

    std::cout << "Testing pop_end:" << std::endl;
    myList.pop_end();  // Expected output: 50

    std::cout << "Testing get_end after pop_end:" << std::endl;
    myList.get_end();  // Expected output: 35

    std::cout << "Testing remove_node 25:" << std::endl;
    myList.remove_node(25);

    std::cout << "Testing find 25 after removal:" << std::endl;
    myList.find(25);  // Expected output: Data is not present in the list

    std::cout << "Testing isEmpty:" << std::endl;
    myList.isEmpty();  // Expected output: List is not empty

    std::cout << "Removing all nodes..." << std::endl;
    myList.pop_start();  // Removing remaining nodes
    myList.pop_start();
    myList.pop_start();
    myList.pop_start();
    myList.pop_start();
    myList.pop_start();  // List should be empty now

    std::cout << "Testing isEmpty after removing all nodes:" << std::endl;
    myList.isEmpty();  // Expected output: List is empty
}

int main() {
    testListOperations();
    std::cout <<"Programme terminated sucesfully"<< std::endl;
    return 0;
}
