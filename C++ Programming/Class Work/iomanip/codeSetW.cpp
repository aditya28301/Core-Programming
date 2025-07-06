#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

int main(void){

    double a;
    a = 10.343434;

    std::cout <<"a = (setw)" << std::setw(5) << a << std::endl;
    std::cout <<"a = (fixed precision)" << std::fixed 
            << std::setprecision(5) << a << std::endl;
    return EXIT_SUCCESS;
}