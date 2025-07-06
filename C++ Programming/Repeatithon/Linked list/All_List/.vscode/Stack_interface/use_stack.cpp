#include <iostream>
#include "Istack.hpp"

int main() {
    // Create a stack instance using the static factory method
    Istack* my_stack = Istack::get_instance(10); // Stack with capacity 5

    // Push elements
    my_stack->push(10);
    my_stack->push(20);
    my_stack->push(30);

    // Display stack
    my_stack->display();

    // Peek top element
    my_stack->peek();

    // Pop an element
    my_stack->pop();
    my_stack->display();

    // Check if full
    if (my_stack->isFull())
        std::cout << "Stack is full\n";
    else
        std::cout << "Stack is not full\n";

    // Check if empty
    my_stack->empty();

    // Clean up
    delete my_stack;
    std::cout <<"Programe end succesfully" << std::endl;
    return 0;
}
