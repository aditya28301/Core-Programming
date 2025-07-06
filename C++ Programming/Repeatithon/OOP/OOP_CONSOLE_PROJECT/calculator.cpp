#include "calculator.hpp"

double calculator::calculate(IOperation* op, double num1, double num2){
    return op->compute(num1, num2);
}

IOperation* calculator::get_instance(int choice){
    switch(choice){

        case 1:
            return new addition;

        case 2:
            return new subtraction;

        case 3:
            return new multiplication;

        case 4:
            return new division;

        default:
            return nullptr;
    }
}

void calculator::release_instance(IOperation* Iptr){
    delete Iptr;
}