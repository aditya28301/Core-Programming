#include <iostream>
#include <memory>
#include <typeinfo>

int main(void){

    // std::shared_ptr<int> ptr(std::make_shared<int>(100));
    std::shared_ptr<int>ptr(new int(10));
    std::shared_ptr<int>ptr2(ptr);
    std::cout <<"Reference_count = " <<ptr2.use_count() << std::endl;
    std::cout<<"raw pointer type = " << typeid(*ptr.get()).name() << std::endl;
    //ptr = nullptr;
    //std::cout <<"Reference_count = " <<ptr.use_count() << std::endl;
    return EXIT_SUCCESS;
}