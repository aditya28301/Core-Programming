#include <stdio.h>
#include <stdlib.h>

struct Date{
    int day;
    int month;
    int year;
};

void int_demo(void);
void float_demo(void);
void date_demo(void);

int main(void)
{
    int_demo();

    return EXIT_SUCCESS;
}

void int_demo(void){
    int* p = NULL;
    
    p = (int*)malloc(sizeof(int));
    if(p == NULL)
    {
        puts("Error in allocating the meomary");
    }

    *p = 100;
    printf("*p = %d\n", 
}