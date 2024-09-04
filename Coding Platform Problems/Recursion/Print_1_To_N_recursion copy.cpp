#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>

void print_one_to_n(unsigned int n, unsigned int i);
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
    print_one_to_n(n, 1);
}
void print_one_to_n(unsigned int n, unsigned int i){
    if(i > n)
        return;
    std::cout << i <<std::endl;
    print_one_to_n(n, i + 1);
}


/*
5
1
2
3
4
5
*/