#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int count_digit(unsigned int number);

int main(void){
    unsigned int num = 0;
    unsigned int count = 0;

    srand(time(0));
    num = rand() % 100;
    count = count_digit(num);
    printf("count of digit %d = %d\n", num, count);
    return 0;
}

unsigned int count_digit(unsigned int num){
    unsigned int temp;
    unsigned int count = 0;
    unsigned int last_digit;

    temp = num;
    while(temp != 0){
        last_digit = temp % 10;
        count += 1;
        temp = temp / 10;
    }
    return count;
}