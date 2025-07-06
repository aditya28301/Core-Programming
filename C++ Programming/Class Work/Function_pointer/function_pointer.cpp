#include <iostream>
#include <cstdlib>
#include <cstdio>

void add(int a, int b);
void callFunction(int a, int b, void (*add)(int, int));
void gen_fun(int a, int b);

int main(void){
    callFunction(100, 200, add);
    void (*ptr_func)(int, int);
    ptr_func = gen_fun;
    ptr_func(1000,2000);
    std::cout <<"Programe terminated succesfully" << std::endl;
    return EXIT_SUCCESS;
}

void gen_fun(int a, int b){
    std::cout <<"a = " << a <<" b = " << b << std::endl;
    std::cout  <<"Generice_function get called here" << std::endl;
}

void callFunction(int a, int b, void (*add)(int, int)){
    add(a, b);
}

inline void add(int a, int b){
    std::cout <<"a = " << a <<" b =" << b << std::endl;
}