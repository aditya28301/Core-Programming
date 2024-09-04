#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define TEST_MAX 100000
typedef int status_t;

status_t check_palindrome(unsigned int num);

int main(void){
    unsigned int num = 0;
    status_t  status = 0;

    srand(time(0));
    for(size_t i = 0; i < TEST_MAX; ++i){
        num = rand() % 999;
        status = check_palindrome(num);
        if(status == TRUE){
            printf("The given number = %lu is palindrome = YES\n", num);
        }
        else
        {
            // printf("The given number = %lu is palindrome = NO\n", num);
        }
    }
    printf("Programme Terminated successfully");
    return 0;
}

status_t check_palindrome(unsigned int num){
    unsigned int temp = 0;
    unsigned int last_digit = 0;
    unsigned int reverse_number = 0;

    temp = num;
    while(temp > 0){
        last_digit = temp % 10;
        reverse_number = reverse_number * 10 + last_digit;
        temp = temp / 10;         
    }
    return (reverse_number == num);
}

/*
    19990
    19990 % 10 =     0   0 * 10 + 0 = 0
    1999 % 10  =     9   0 * 10 + 9 = 9   

*/