#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE    1
#define FALSE   0

void print_divisor(unsigned int num);

int main(void){
    unsigned int num;
    int status = 0;
    srand(time(0));
    num = 12;
    print_divisor(num);
    printf("Programmer terminated sucessfully");
    return EXIT_SUCCESS;
}

void print_divisor(unsigned int num){
    printf("List of number of divisible\n");
    for(size_t i = 1; i <= num; ++i){
        if(num % i == 0)
            printf("[%llu] ", i);
    }

    printf("\n\n");

    printf("List of number is not divisible\n");
    for(size_t i = 1; i <= num; ++i){
        if(num % i != 0)
            printf("[%llu] ", i);
    }
    printf("\n");
}


/*
    num % 10 == 0 == yes
    num % 10 > 0 == NO
    4 * 4 * 4
    1 * 3 = 3
    1(3) + 1(3) + 1(3)  
    1 + 1 + 1 = 
*/