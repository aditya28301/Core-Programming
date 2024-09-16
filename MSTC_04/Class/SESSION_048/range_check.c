/*
@Goal: This program asks end user to enter a positive integer.
(Validation check is performed). Let this integer be calledas N.

The program asks end user to enter another integer value, say i

0 <= i <= N-1
This is a desired range for i.

The program should output whether is in desire range or not
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N;  
    int i; 

    printf("Enter a Positive integer\n");   /* N is a positive integer will user Entered */
    scanf("%d", &N);
    
    if(N <= 0)
    {
        printf("Entred number is not positive\n");
        exit(-1);
    }
    
    puts("Entered second integer number for 'i'");  /*  User will entered another integer number */
    scanf("%d", &i);

    if(0 <= i && i <= N-1)
    {
        printf("The value you entered for 'i' integer is withing range =%d\n", i);
    }
    else
    {
        printf("Value is not within rangr......\n Please check range for value 'i' =%d\n", i);
    }
    exit(0);
}