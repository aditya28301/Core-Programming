#include <stdio.h>

int main(void)
{
    int i;

    puts("start of while loop");    
    i = 0;
    while(i < 5 )
    {
        printf("i = %d\n", i);
        i = i + 1;
    }
    puts("end of while loop");
    
    puts("start of for loop");
    for(i = 0; i < 5; i++)
    {
        printf("i = %d\n", i);
        puts("end of for loop");
    }
    return (0);
}