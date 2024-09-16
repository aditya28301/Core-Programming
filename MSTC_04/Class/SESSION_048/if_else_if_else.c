#include <stdio.h>
int main(void)
{
    int n;

    puts("start of program");
    printf("Enter an integer");
    scanf("%d", &n);

    if(n > 0)
    {
        puts("n is positive");
    }
    else if(n < 0)
    {
        puts("n is negative");
    }
    else 
    {
        puts("n is zero");
    }
    puts("end of program");
    return (0);
}