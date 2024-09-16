#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>
template <typename T> void cal(T num1, T num2){
    T sum;
    sum = num1 + num2;
    std::cout << "sum is = " << sum << std::endl;
}

int main(void){
    int num1, num2;
    double fnum1, fnum2;

    num1 = 100;
    num2 = 200;

    fnum1 = 1.1;
    fnum2 = 2.2;

    cal<int>(num1, num2);
    cal<float>(fnum1, fnum2);
    std::cout <<"Programme terminated sucesfully" << std::endl;
    return EXIT_SUCCESS;
}