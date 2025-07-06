// main.cpp
#include "list.hpp"

int main() {

    Ilist* list = Ilist::getInstance();

    std::cout << "Inserting elements...\n";
    list->insert_start(10);
    list->insert_end(30);
    list->insert_after(10, 20);
    list->insert_before(30, 25);
    list->show_list();

    std::cout << "\nTesting get_start, get_end:\n";
    list->get_start();
    list->get_end();

    std::cout << "\nLength check:\n";
    list->get_len();

    std::cout << "\nRemoving elements:\n";
    list->remove_data(20);
    list->pop_start();
    list->pop_end();
    list->show_list();

    std::cout << "\nIs list empty? " << (list->isEmpty() ? "Yes" : "No") << "\n";

    list->get_len();

    list->show_list();
    list->pop_end();
    list->show_list();
    Ilist::released_instance(list);
    std::cout<<"programe terminated succesuflly" << std::endl;
    return 0;
}
