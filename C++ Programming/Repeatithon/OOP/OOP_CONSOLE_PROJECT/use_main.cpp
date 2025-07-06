#include "calculator.hpp"
#include <iostream>
#include <cstdlib>

int main(void){
	calculator* cal = new calculator;

	IOperation* iptr = calculator::get_instance(VALUE);
	double result = 0.0;
 
	result = cal->calculate(iptr, 100, 200);
	std::string name;
	switch(VALUE){
		case 1:
			name = "Addition";
			break;
		case 2:
			name = "Subtraction";
			break;
		case 3:
			name = "Multiplication";
			break;
		case 4:
			name = "Division";
			break;
		default:
			name = "Wrong input";
			break;
	}

	std::cout <<name <<"of 100, 200 is = " << result << std::endl;

	calculator::release_instance(iptr);
	delete cal;

	std::cout<<"Programe terminated succesfully" << std::endl;
	return EXIT_SUCCESS;
}
