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
    char count = '\0';
    size_t j = 0;
    for(size_t  i = 0 ; i < input; ++i){
        count = 'A';
        // space
        for(size_t s = 0; s < input - i; ++s){
            printf("  ");
        }

        // character
        for(j = 0; j < 1 + ((i+1) - 1) * 2; ++j){
            printf("%c ", count);

            if(j == i){
               count = count - 1;
                ++j;
                break;
            }
            ++count;
        }

        // // printf("->%llu\n", j);
        for(; j < 1 + ((i + 1) - 1) * 2; ++j){
            printf("%c ", count);
            --count;
        }

        // Space
         for(size_t j = 0; j < input - i; ++j){
            printf("  ");
        }

    printf("\n");
    }
}   
 