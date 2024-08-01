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

void pattern_first_half(size_t input);
void pattern_second_half(size_t input);

int main(int argc, char* argv[]){
    size_t input;

    if(argc != 2){
        puts("INPUT NOT PROVIDED");
        exit(EXIT_FAILURE);
    }

    input = strtoul(argv[1], NULL, 10);
    pattern_first_half(input);
    pattern_second_half(input);

    return (0);
}
void pattern_second_half(size_t input){
    for(size_t i = 0; i < input; ++i){
        for(size_t j = 0; j < (input - (input - 1 - i) - 1) ; ++j){
            printf("  ");
        }

        for(size_t k = 0; k < 1 + (input - 1 - i) * 2; ++k){
            printf("* ");
        }    

        for(size_t j = 0; j < (input - (input - 1 - i) - 1) ; ++j){
            printf("  ");
        }
        printf("\n");
    }
}

void pattern_first_half(size_t input){
   for(size_t i = 0; i < input; ++i){
        for(size_t j = 0; j < input - i - 1; ++j){
            printf("  ");
        }

        for(size_t k = 0; k < 1 + (i) * 2; ++k){
            printf("* ");
        }

        for(size_t j = 0; j < input - 1 - i; ++j){
            printf("  ");
        }
        printf("\n");
   }
}
