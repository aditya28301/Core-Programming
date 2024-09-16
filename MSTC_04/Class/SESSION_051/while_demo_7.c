#include <stdio.h>

int main(void)
{
    int i;

    puts("start of program");
    i = 0;
    while(i < 5)
    {
        printf("i = %d\n", i);
        i = i + 1;
    }
    puts("end of program");
    return (0);
} 

