/*
    @Autor  :Aditya Ashok Darekar
    @Date   :14 July 2024
    @Goal   : Print below provided pattern for n input.
            
                            *
                        *   *   *
                    *   *   *   *   *
                *   *   *   *   *   *   *
            *   *   *   *   *   *   *   *   *
*/

#include <stdio.h>
#include <stdlib.h>

void pattern(size_t input);
int main(int argc, char* argv[]){
    size_t input;

    if(argc != 2){
        puts("INPUT NOT PROVIDED");
        exit(0);
    }

    input = strtoul(argv[1], NULL, 10);
    pattern(input);
    return (0);
}

void pattern(size_t input){
    size_t i, j , k = 0;
    size_t space = 0;
    static count = 0;
    // printf("[%d]\n", count);
    if(count < input){
        space = input - count -1;
        for(i = 0; i < space ; ++i)
            printf("  ");
        for(j = 0; j < 1 + ((count+1 - 1) * 2);  ++j)
            printf("* ");
        for(k = 0; k < space; ++k)
            printf("  ");
        printf("\n");
        ++count;
        pattern(input);
    }
}
