#include "apple.hpp"

void run(void);

int main(void){
    run();
    std::cout << "Programme terminated sucesfully " << std::endl;
    return 0;
}

void run(void){
    IApple* kishor_kumar = 0;
    kishor_kumar = apple::get_instance("O sathi re", 9999);
    kishor_kumar->play();
    kishor_kumar->next();
    kishor_kumar->prev();
    kishor_kumar->add_song();
    apple::release_instance(kishor_kumar);
}