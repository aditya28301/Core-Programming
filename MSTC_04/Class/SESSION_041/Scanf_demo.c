#include <stdio.h>

int main(void){
    
    int num =0;

    printf("Initial value of num = %d\n", num);
    printf("Please enter value to be stored in num:\n");
    scanf("%d", &num);
    printf("Value stored in num after scanf():%d\n", num);

    return (0);
}
