#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>

void print_n_to_one(unsigned int i);
void print(unsigned int n);

int main(void){
    srand(time(0));
    unsigned int random_number = 0;
    random_number = rand() % 10 + 1;
    print(random_number);
    std::cout <<"Programme terminated sucesfully";
    return EXIT_SUCCESS;
}

void print(unsigned int n){
    print_n_to_one(n);
}
void print_n_to_one(unsigned int i){
    if(i < 1)
        return;
    std::cout << i <<std::endl;
    print_n_to_one(i - 1);  
}

/*
    5
    4
    3
    2
    1
    0
*/