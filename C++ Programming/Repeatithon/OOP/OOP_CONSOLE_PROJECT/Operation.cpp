#include "Operation.hpp"

addition::addition() { }
subtraction::subtraction() { }
multiplication::multiplication() { }
division::division() { }

inline double addition::compute(double num1, double num2){
    return (num1 + num2);
}

double subtraction::compute(double num1, double num2){
    if(num1 > num2)     
        return num1 - num2;
    else   
        return num2 - num1;
}

inline double multiplication::compute(double num1, double num2){
    return (num1 * num2);
}

inline double division::compute(double num1, double num2){
    return (num1 / num2);
}