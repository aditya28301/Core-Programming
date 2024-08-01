#include "operator.hpp"

int main(void){
	opt o1(10);
	opt o2(20);

	opt result;
	
	result  = o1 + o2;
	result.show("Addition of o1 + o2");
	
	result = o2 - o1;
	result.show("Subtraction of o2 - o1");

	result = o1 * o2;
	result.show("Multiplication of o1 * o2");

	result = o1 / o2;
	result.show("Division of o1 / o2");
	
	result = o1 % o2;
	result.show("Modolus of o1 % o2");
	
	result = o1 << o2;
	result.show("Left shift of o1 << o2");

	result = o1 >> o2;
	result.show("Right shift of o1 >> o2");

	result = o1 && o2;
	result.show("o1 && o2 Logical operator");

	result = o1 || o2;
	result.show("o1 || o2 Logical operator");

	result = !o1;
	result.show("o1 is Logical not operator");

	result = o1 & o2;
	result.show("o1 & o2 is Bitwise and operator");

	result = o1 | o2;
	result.show("o1 and o2 is Bitwise or operator");

	result = o1 ^ o2;
	result.show("o1 and o2 is Bitwise is xor opeator");

	result = ~o1;
	result.show("o1 is bitwise not operator");

	result = o1 < o2;
	result.show("o1 < o2 is comparision operator");

	result = o1 <= o2;
	result.show("o1 <= o2 is comparision opeartor");
		
	result = o1 > o2;
	result.show("o1 > o2 is comparision operator");

	result = o1 >= o2;
	result.show("o1 >= o2 is comparision operator");

	result = o2 == o1;
	result.show("o1 == o2 is comparison operator");

	result = o1 != o2;
	result.show("o1 != o2 is comparison opereator");

	result = ++o1;
	result.show("Preincrement of o1");

	result = o1++;
	result.show("PostIncrement of o1");
	o1.show("Postincrement of o1");

	opt o3(200);
	std::cout << "Cout Overload " << o3 << std::endl;

	puts("Programme Terminated succesfully");
	
	opt o4(400);
	std::cout <<"cout overload" << o4 << std::endl;

	opt o5;
	std::cin >> o5;

	std::cout <<"Object o5 is=" <<o5<<std::endl;
	return 0;
}