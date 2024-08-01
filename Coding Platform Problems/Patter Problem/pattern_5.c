/*
    @Autor  :Aditya Ashok Darekar
    @Date   :14 July 2024
    @Goal   : Print below provided pattern for n input.
            1   2   3   4   5
            1   2   3   4
            1   2   3   
            1   2
            1
*/

#include <stdio.h>
#include <stdlib.h>

void pattern(size_t input);
int main(int argc, char* argv[]){
    size_t input;

    if(argc != 2)
        puts("INPUT NOT PROVIDED");

    input = strtoul(argv[1], NULL, 10);
    pattern(input);
    return (0);
}

void pattern(size_t input){
    for(size_t i = 0; i < input; ++i){
        for(size_t j = 0; j <= (input - i - 1); ++j){
            printf("%llu ", j+1);
        }   
        printf("\n");
    }
}
