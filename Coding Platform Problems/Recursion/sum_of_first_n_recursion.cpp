#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>

unsigned int sum(unsigned int i, unsigned int n);
void print(unsigned int n);

int main(void){
    srand(time(0));
    unsigned int random_number = 0;
    random_number = rand() % 10 + 1;
    std::cout <<"n= " << random_number << std::endl;
    print(random_number);
    std::cout <<"Programme terminated sucesfully";
    return EXIT_SUCCESS;
}

void print(unsigned int n){
    unsigned int total = 0;
    total = sum(1, n);
    std::cout << total << std::endl;
}
unsigned int sum(unsigned int i, unsigned int n){
    static unsigned int total = 0;
    if(i > n)
        return 0;
    sum(i+1, n);
    total+= i;
    return total;
}

/*
1 + 14
2 + 12
3 + 9
4 + 5
5
*/