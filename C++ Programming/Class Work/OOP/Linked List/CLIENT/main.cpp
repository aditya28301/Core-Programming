#include "IList.hpp"
#pragma comment (lib, "List.lib")

void run(void);
int main(void){
    run();
    std::cout <<"Programme terminated sucesfully";
    return EXIT_SUCCESS;
}   

void run(void){
    data_t start = 0;
    data_t end = 0;
    data_t len = 0;
    status_t status = 0;

    IList* list = 0;
    list = IList::get_instance();
    std::cout <<"insert_start" << std::endl;
    for(size_t i = 0; i < TEST_MAX; ++i)
        list->insert_start(i);
    std::cout <<"insert_end" << std::endl;
    list->insert_end(99);
    std::cout <<"show" << std::endl;
    list->show();

    std::cout <<"insert_after" << std::endl;
    list->insert_after(2, 100);
    std::cout <<"insert_before" << std::endl;
    list->insert_before(3, 200);
    std::cout <<"show" << std::endl;
    list->show();
    std::cout <<"get_start" << std::endl;
    list->get_start(&start);
    std::cout <<"start = " << start << std::endl;
    list->get_end(&end);
    std::cout <<"end = " << end << std::endl;
    std::cout <<"Pop start" << std::endl;
    list->pop_start(&start);
    std::cout <<"Pop start = " << start << std::endl;
    std::cout <<"start" << start << std::endl;
    list->pop_end(&end);
    std::cout <<"end" << end << std::endl;
    std::cout <<"find" << std::endl;
    status = list->find(100);
    std::cout << status << std::endl;
    std::cout <<"isEmpty" << std::endl;
    status = list->isEmpty();
    std::cout << status << std::endl;
    std::cout <<"get_len" << std::endl;
    len = list->getLen();
    std::cout <<len << std::endl;
    std::cout <<"show" << std::endl;
    list->show();
    std::cout << len << std::endl;
    std::cout <<"show" << std::endl;
    list->show();
    std::cout <<"Release instance" << std::endl;
    IList::release_instance(list);
}