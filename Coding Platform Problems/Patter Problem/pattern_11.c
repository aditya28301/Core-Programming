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
    size_t space = 2 * input;
    size_t incre = 0;

    for(size_t i = 1; i <=input; ++i){
        incre = incre + 2;
        for(size_t j = 1; j <= i; ++j){
            printf("%llu ", j);
        }

        for(size_t j = 1; j <= space - incre; ++j){
            printf("  ");
        }

        for(size_t j = i; j >= 1; --j){
            printf("%llu ", j);
        }
        printf("\n");
   }
}
