#include "list.hpp"

int main(void){
    list* l1 = new list();
    l1->insert_start(10);
    l1->insert_end(20);
    l1->insert_after(10, 15);
    l1->insert_before(20,17);
    std::cout << *l1 << std::endl;
    l1->get_start();
    l1->get_end();
    l1->pop_start();
    l1->pop_end();
    l1->remove_data(20);
    l1->isEmpty();
    l1->get_len();
    std::cout <<"ORIGNAL LIST" << std::endl;
    std::cout << *l1 << std::endl;
    std::cout <<"Moving data from one list another" << std::endl;
    list* l2 = new list(std::move(*l1));
    std::cout <<"LIST L1" << std::endl;
    std::cout <<*l1 << std::endl;
    std::cout <<"LIST L2" << std::endl;
    std::cout << *l2 << std::endl;
    std::cout <<"Programe terminated sucesfully" << std::endl;
    return EXIT_SUCCESS;
}