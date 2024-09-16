#include <stdio.h> 

int main(void)
{
    int a[5]; 
    int i; 

    for(i = 0; i < 5; i = i + 1)
    {
        printf("Enter the value for integer at index %d:", i); 
        scanf("%d", &a[i]); 
        
    }

    for(i = 0; i < 5; i = i + 1)
    {
        printf("a[%d]:%d\n", i, a[i]); 
    }

    return (0); 
}

