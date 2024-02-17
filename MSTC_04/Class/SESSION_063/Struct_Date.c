#include <stdio.h>

struct Date
{
    int day;
    int month;
    int year;  
};

struct Date my_date_1;
struct Date my_date_2;

int main(void)
{
    int dd;
    int mm;
    int yy;

    my_date_1.month  = 9;
    my_date_1.day   = 20;
    my_date_1.year  = 2001;

    dd = my_date_1.day;
    mm = my_date_1.month;
    yy = my_date_1.year;

    printf("date = %d , month = %d, year = %d\n", dd , mm , yy);

    /*Structure Date 2 */
    my_date_2.day = 8;
    my_date_2.month = 10;
    my_date_2.year = 2002;

    dd = my_date_2.day;
    mm = my_date_2.month;
    yy = my_date_2.year;

    printf("dd = %d, mm =%d , yy =%d\n", dd, mm, yy);

    return (0);
}
