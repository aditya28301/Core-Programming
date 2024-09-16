#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    int c = 0;
    puts("start of the program");

    printf("Enter n:");
    scanf("%d", &n);

    if(n > 0)
    {
        c = 100;
        puts("n is greater than 0");
    }

    printf("c = %d\n", c);
    puts("end of program");

    exit(0);
}