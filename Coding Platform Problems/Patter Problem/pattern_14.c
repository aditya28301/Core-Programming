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
    for(size_t  i = input ; i > 0; --i){
        count = 'A';
        for(size_t j = 1; j <= i; ++j){
            printf("%c ", count);
            ++count;
        }
    printf("\n");
    }
}   
 