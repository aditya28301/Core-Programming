#include <stdio.h>

int main(void){
    int n = 100;
    int* p =0;

    printf("n = %d\n", n);
    printf("&n = %p\n", &n);
    p = &n;
    printf("p = %p\n", p);

    return (0);
}