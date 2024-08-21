#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int reversed_number(unsigned int number);

int main(void){
    unsigned long long int num = 0;
    unsigned long long int rev_no = 0;
    srand(time(0));
    num = 78787999097;
    rev_no = reversed_number(num);
    printf("reversed_number %llu = %llu\n", num, rev_no);
    return 0;
}

unsigned int reversed_number(unsigned int num){
    unsigned int temp;
    unsigned int rev_no = 0;
    unsigned int last_digit;

    temp = num;
    while(temp != 0){
        last_digit = temp % 10;
        rev_no = rev_no * 10 + last_digit;
        temp = temp / 10;
    }
    return rev_no;
}

/*1348

0 * 10 + 8 = 0 + 8 = 8
8 * 10 + 4 = 80 + 4 = 84
84 * 10 + 3 = 840 + 3 = 843
843 * 10 + 1 = 8430 + 1 = 8431

*/