#include "IApple.hpp"

void run(void);
#pragma comment(lib, "apple.lib")

int main(void){
    run();
    std::cout << "Programme terminated sucesfully " << std::endl;
    return 0;
}

void run(void){
    IApple* kishor_kumar = 0;
    kishor_kumar = IApple::get_instance("O sathi re", 9999);
    kishor_kumar->play();
    kishor_kumar->next();
    kishor_kumar->prev();
    kishor_kumar->add_song();
    IApple::release_instance(kishor_kumar);
}