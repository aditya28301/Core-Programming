#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>

template <int n> void add(int num1, int num2){
    int sum = 0;
    sum = num1 + num2 * n;
    std::cout <<"sum is = " << sum << std::endl;
}
int main(void){
    add<10>(100,200);
    add<10>(500, 500);
    std::cout <<"Programme termianted sucessfully";
    return EXIT_SUCCESS;
}