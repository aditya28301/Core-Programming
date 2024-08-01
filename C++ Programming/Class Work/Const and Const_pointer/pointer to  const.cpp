#include <cstdio>

int main(void){
    //pointer
    int a;
    int b;
    int* ptr = NULL;

    a = 10;
    b = 20;

    ptr = &a;
    printf("pointer[%d]\n", *ptr);

    //pointer const
    const int* c_ptr = &a; 
    // *c_ptr = 100; ERROR

    printf("pointer address can be change but not value [%d]\n", *c_ptr);

    //const pointer
    int* const p = &a;
    // p = &b; ERROR
    *p = 100;
    printf("pointer address cannot be changed but value can[%d]\n", *p);

    //const pointer to const 
    const int* const pp = &b;
    // *pp = 200;   ERROR
    //  p = &a;     ERROR
    
    printf("Both pointer value and address cannot be changed[%d]\n", *pp);
    return 0;
}