#include <cstdio>
#include <cstdlib>
#include <iostream>

typedef unsigned long long int data_t;

data_t factorial(data_t n);

int main(void){
    data_t result = 0;
    result = factorial(5);
    std::cout <<"result = "<< result << std::endl;
    return EXIT_SUCCESS;
}

data_t factorial(data_t n){
    data_t sum = 0;
    if(n == 1)
        return 1;
    sum += n * factorial(n-1);
    return sum;
}   
/*
    5 * 4 = 100
    4  * 3 = 24
    3 * 2 = 6
    2 * 1 = 2
    1   = return
*/

