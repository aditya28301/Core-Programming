#include <stdio.h>

int main(void)
{
    int i;

    puts("start of program");

    printf("Enter an integer");
    scanf("%d", &i);

    switch(i)
    {
        case 1:
            puts("Entered integer is 1");
            break;
        case 2:
            puts("Entered integer is 2");
            break;
        case 3:    
            puts("Enter integer is 3");
            break;
        default:
            puts("Integer other than 1, 2 and 3 is entred");
            break;
    }
    puts("end of program");
    return (0);
}