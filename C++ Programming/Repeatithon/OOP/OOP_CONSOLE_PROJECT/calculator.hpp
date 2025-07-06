#include "Ioperation.hpp"
#include "Operation.hpp"
/*
	1 -> addition
	2 -> subtraction
	3 -> multiplication
	4 -> division
*/

const int VALUE = 1;

class calculator{
    public:
        double calculate(IOperation* op, double num1, double num2);
        static IOperation* get_instance(int choice);
        static void release_instance(IOperation* Iptr);

};