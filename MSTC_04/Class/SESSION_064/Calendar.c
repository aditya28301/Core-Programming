#include <stdio.h>
#define YEAR 12
#define MAX_DATE 31
#define DAY_IN_WEEK 7
#define ROW 5
typedef unsigned int Positive;

void Set_Date(struct Calendar*, Positive, Positive);
void printing_calendar(struct Calendar*, Positive);
void print_day(struct Calendar*, Positive);

enum Month
{
    JAN = 1,
    FEB,
    MAR,
    APR,
    MAY,
    JUNE,
    JULY,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC
};

struct Calendar
{   
    Positive month;
    Positive year;
    Positive day[MAX_DATE];
};

int main(void)
{
    int month[] = {JAN,FEB,MAR,APR,MAY,JUNE,JULY,AUG,SEP,OCT,NOV,DEC};
    struct Calendar cal[YEAR];
    Positive Year = 0;

    printf("Enter the Year that you want see calendar\n");
    scanf("%d", &Year);

    Positive i = 0;
    while(i < YEAR)
    {
        cal[i].year = Year; 
        cal[i].month = month[i];

        Set_Date(&cal[i], MAX_DATE, month[i]);
        
        //printf("correct->%d\n",cal[i].day[1]);
        i = i + 1;
    }
    
        printing_calendar(cal, YEAR);   
    return (0);
}

void Set_Date(struct Calendar *cal, Positive count, Positive month)
{
    Positive DayLoop_value = 0;
    switch(month)
    {
        case JAN:
        case MAR:
        case MAY:   
        case JULY:
        case AUG:
        case OCT:
        case DEC:
            DayLoop_value = 31;
            break;
        case APR:
        case JUNE:
        case SEP:
        case NOV:
            DayLoop_value = 30;
            break;
        case FEB:
            DayLoop_value = 29;
            break;

        default:
            break;
    }

    int date = 0;
    int j = 0;
    while(j <= DayLoop_value)
    {
        if(j != DayLoop_value)
        {
            date = j + 1;
        }
        else
        {   
            date = j;
        }
        cal->day[j] = date;
        // printf("chec->%d\n",cal.day[j]);
        
        j = j + 1;
    }
}

void printing_calendar(struct Calendar *cal, Positive year)
{
    int i = 0;

    printf("Year %d\n", cal[0].year);

    while(i < year)
    {
        if(cal[i].month == JAN)
        {
            printf("JAN\n");
            // printf("Second chec->%d\n",cal[0].day[1]);
            print_day(&cal[i], 31);
        }
        else if(cal[i].month == FEB)
        {
            printf("FEB\n");
            print_day(&cal[i], 29);
        }   
        else if(cal[i].month == MAR)
        {
            printf("MAR\n");
            print_day(&cal[i], 31);
        }
        else if(cal[i].month == APR)
        {
            printf("APR\n");
            print_day(&cal[i], 30);
        }
        else if(cal[i].month == MAY)
        {
            printf("MAY\n");
            print_day(&cal[i], 31);
        }
        else if(cal[i].month = JUNE)        
        {
            printf("JUNE\n");
            print_day(&cal[i], 30);
        }   
        else if(cal[i].month == JULY)   
        {
            printf("JULY\n");
            print_day(&cal[i], 31);
        }
        else if(cal[i].month == AUG)
        {   
            printf("AUG\n");   
            print_day(&cal[i], 31);
        }  
        else if(cal[i].month == SEP)
        {
            printf("SEP\n");
            print_day(&cal[i], 30);
        }
        else if(cal[i].month == OCT)
        {
            printf("OCT\n");
            print_day(&cal[i], 31);
        }
        else if(cal[i].month == NOV)
        {
            printf("NOV\n");
            print_day(&cal[i], 30);
        }
        else
        {
            printf("DEC\n");
            print_day(&cal[i], 31);
        }
        i = i + 1;
    }
}




void print_day(struct Calendar *cal, Positive size)
{
    int i = 0;
    while(i < ROW)
    {
        int j = 0;
        while(j < DAY_IN_WEEK)
        {
            if( !(j == 31))
            {
                printf("%d ",cal->day[i * DAY_IN_WEEK + j]);
            }

            j = j + 1;
        }
        printf("\n");
        i = i + 1;
    }
}

// jan 
// 1 2 3 4 5 6 7
// 8 9 10 11 12 13 14
// 15 16 17 18 19 20
// 21 22 23 24 25 26 27
// 28 29 30 31
