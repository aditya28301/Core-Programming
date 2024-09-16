#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>

typedef unsigned long long int data_t;

data_t fibnacii_sereis(data_t N);
int main(void){
    srand(time(0));
    data_t N = 0;
    data_t sum = 0;
    N = rand() % 100 + 1;
    // N = 5;
    std::cout <<"Nth term called for = "<<N<< std::endl;
    sum = fibnacii_sereis(N);
    std::cout <<"Fibancci series sum is = " << sum << std::endl;
    std::cout <<"Programe termianted sucesfully" << std::endl;
    return EXIT_SUCCESS;
}

data_t fibnacii_sereis(data_t N){
    std::cout<<"called = " << N << std::endl;
    if(N <= 1)
        return N;
    return fibnacii_sereis(N-2) + fibnacii_sereis(N-1);
}   