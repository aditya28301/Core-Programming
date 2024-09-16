#include <stdio.h>

void calendar(void);
int main(void)
{
    calendar();
    return (0);
}

void calendar(void)
{
    int i;
    int j;
    int k;
    int month;
    int year;
    int date;

    month = 12;
    date = 31;
    year = 1;
    for(i = 0; i < year; ++i)
    {
        printf("year = %d\n", i+1);
        for(j = 0; j < month; ++j)
        {
            printf("month = %d\n", j+1);
            for(k =0; k < date; ++k)
            {
                if(j == 1 && k == 28)
                {
                    break;
                }
                printf("day= %d\n",k+1); 
            }
        }
        puts("\n");
    }
}

