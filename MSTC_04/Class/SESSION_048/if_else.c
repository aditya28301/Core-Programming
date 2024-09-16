#include <stdio.h>
#include <stdio.h>
#include <stdio.h>
int main(void)
{
    int n;
    int c = 0;

    puts("start of program");
    printf("Enter an integer:");
    scanf("%d", &n);


;    if(n > 0)
    {
        c = 100;
        printf("n is positive , c=%d\n", c);
    }
    else
    {
        c = 200;
        printf("n is zero or negative, c =%d\n", c);
    }

    puts("end of program");
    return (0);
}