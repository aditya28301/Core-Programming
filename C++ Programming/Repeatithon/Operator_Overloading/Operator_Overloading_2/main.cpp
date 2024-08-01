#include "operator.hpp"

size_t add(size_t num1, size_t num2){
	return num1 + num2;
}

int main(void){
	opt o(10);
	
	std::cout <<"input a number in array"
			  <<std::endl;
	for(size_t i = 0; i < 10; ++i)
		o[i] = ( i + 1) * 100;

	std::cout <<"Display the number" <<std::endl;
	for(size_t i = 0; i < 10; ++i){
		std::cout << o[i]
			 << std::endl;
	}

	opt2 o2;
	size_t ret;
	o2.set(add);
	ret = o2(1000,2000);
	std::cout <<"Addition of two number=" << ret <<std::endl;
	std::cout <<"Programme termianted succesfully" <<std::endl;
	return 0;
}