#include <stdio.h>

void input_array(void);
void break_demo(void);
void continue_demo(void);   

int a[8]; 
int i;

int main(void)
{
    break_demo();
    continue_demo();
    return (0);
}

void input_array(void)
{
    i = 0;
    while(i < 8)
    {
        printf("Enter the value for integer at index %d:", i);
        scanf("%d", &a[i]);
    }
}

void break_demo(void)
{
    puts("start break_demo");
    i = 0;
    while(i < 8)
    {
        if(a[i] %7 == 0)
        {
            break;
        }
        printf("a[%d]:%d\n", i, a[i]);
        i = i + 1;
    }
        puts("end break_demo");
}

void continue_demo(void)
{
    puts("start continue_demo");
    i = 0;
    while(i < 8)
    {
        if(a[i] % 7 == 0)
        {
            i = i + 1;
            continue;
        }
        printf("a[%d]:[%d]\n", i, a[i]);
        i = i + 1;
    }
puts("end continue_demo");
}