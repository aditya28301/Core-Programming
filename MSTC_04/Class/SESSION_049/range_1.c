/*
@ Goal : Input an integer frin the end user. Call it 'n;
Check for the following ranges:
0 <= n <= 5
0 < n <= 5
0 <= n < 5
0 < n < 5

You must print which of the above ranges are true
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;

    printf("Enter a value for n:");
    scanf("%d", &n);

    if(0 <= n && n <=5)
        puts("0 <= n <= 5 is TRUE");

    if(0 < n && n <= 5)
        puts("0 < n=5 is TRUE");
    
    if(0 <=n && n < 5)
        puts("0 < n && n < 5 is TRUE");

    if(0 < n && n < 5)
        puts("0 < n && n < 5 is TRUE");
    return (0);
}