#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE    1
#define FALSE   0

unsigned int  ifArmstrong(unsigned int num);

int main(void){
    unsigned int num;
    int status = 0;
    srand(time(0));
    num = 755;
    status = ifArmstrong(num);
    if(status == TRUE)
        puts("Armstrong number is = YES");
    else
        puts("Armstrong number is = NO");
    printf("Programmer terminated sucessfully");
    return EXIT_SUCCESS;
}

unsigned int ifArmstrong(unsigned int num){
    unsigned int temp = 0;
    unsigned int last_digit = 0;
    unsigned int sum = 0;
    unsigned int power = 0;
    temp = num;
    while(temp != 0){
        last_digit = temp % 10;
        power = last_digit;
        for(size_t i = 0; i < 2; ++i)
            power = power * last_digit;
        sum = sum + power;
        temp = temp / 10;
    }
    if(sum == num)
        return TRUE;
    return FALSE;
}

/*
    4 * 4 * 4
    1 * 3 = 3
    1(3) + 1(3) + 1(3)  
    1 + 1 + 1 = 
*/