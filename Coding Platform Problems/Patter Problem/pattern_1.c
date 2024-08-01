/*
    @Autor  :Aditya Ashok Darekar
    @Date   :14 July 2024
    @Goal   : Print below provided pattern for n input.
            *
            *   *
            *   *   *
            *   *   *   *
            *   *   *   *   *
*/

#include <stdio.h>
#include <stdlib.h>

void pattern(size_t n);

int main(int argc, char* argv[]){
    size_t input;

    if(argc != 2)
        puts("NO INPUT PROVIDED");

    input = strtoul(argv[1], NULL, 10);
    pattern(input);

    return  (0);
}

void pattern(size_t n){
    for(int i = 0; i < n; ++i){
        for(size_t j = 0; j <= i; ++j){
            printf("* ");
        }
    printf("\n");
    }
}