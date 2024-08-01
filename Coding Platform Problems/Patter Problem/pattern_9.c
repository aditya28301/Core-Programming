/*
    @Autor  :Aditya Ashok Darekar
    @Date   :14 July 2024
    @Goal   : Print below provided pattern for n input.

            *   *   *   *   *   *   *   *   *
                *   *   *   *   *   *   *
                    *   *   *   *   *
                        *   *   *
                            *
*/

#include <stdio.h>
#include <stdlib.h>

void pattern(size_t input);

int main(int argc, char* argv[]){
    size_t input;

    if(argc != 2){
        puts("INPUT NOT PROVIDED");
        exit(EXIT_FAILURE);
    }

    input = strtoul(argv[1], NULL, 10);
    pattern(input);

    return (0);
}
void pattern(size_t input){
   for(size_t i = 0 ; i < input; ++i){
        for(size_t j =0; j <= i; ++j){
            printf("* ");
        }
        printf("\n");
   }

     for(size_t i = 0; i < input - 1; ++i){
        for(size_t j = 0; j < input - 1 - i; ++j){
            printf("* ");
        }
        printf("\n");
   }
}
