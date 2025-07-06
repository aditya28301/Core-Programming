#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

class A{
	private:
		int a;
		int b;	
	public:
	A() : a(10), b(20) {	std::cout << " Default constructor is called here" << std::endl; }
	A(int a_, int b_) : a(a_), b(b_) { std::cout << "parameterised constructor called here" << std::endl;}  
	void get_value(){
		std::cout << "a = " << a << "b = " << b << std::endl;	
	}
};

int main(void){
	A obj1;
	A obj2(obj1);
	obj2.get_value();
	std::cout << "Programme terminated sucesfully" << std::endl;
	return EXIT_SUCCESS;
}

