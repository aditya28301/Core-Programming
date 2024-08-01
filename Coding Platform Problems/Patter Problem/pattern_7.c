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

    if(argc != 2)
        puts("INPUT NOT PROVIDED");

    input = strtoul(argv[1], NULL, 10);
    pattern(input);
    return (0);
}

void pattern(size_t input){
    for(size_t i = 0; i < input; ++i){
        for(size_t j = 0; j < (input - (input - i - 1)) - 1; ++j ){
            printf("- ");
        }       

        for(size_t k = 0; k < 1 + ((input - 1 - i)) * 2; ++k){
            printf("* ");
        }

        for(size_t j = 0; j < (input - (input -1 - i)) - 1; ++j){
            printf("- ");
        }  
        printf("\n");
    }
}
