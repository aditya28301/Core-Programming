#include <stdio.h>
#include <stdlib.h>

unsigned long long int fact(unsigned long long int n);

int main(void)
{
    printf("Factorial of 20 =%llu\n", fact(20));

    return (0);
}

unsigned long long int fact(unsigned long long int n)
{
   unsigned long long int result;

    if(n == 1)
        return 1;

    result = n * fact(n-1);
    return result;
}