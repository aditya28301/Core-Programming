#include "operator.hpp"

size_t add(size_t i1, size_t i2);
int main(void){
	opt o(10);
	std::cout<<"Getting input in array" << std::endl;
	for(size_t i =0 ; i < 10; ++i)
		o[i] = (i + 1) * 100;

	std::cout <<"Display output on screen"<< std::endl;
	for(size_t i =0 ; i < 10; ++i)
		std::cout << o[i] <<std::endl;


	std::cout<<"Call operator overloaded" << std::endl;
	opt2 o2;
	size_t ret;
	o2.set(add);
	ret = o2(100,200);
	std::cout <<"addition of two number= "<< ret <<std::endl;
	
	std::cout <<"Programme terminated succesfully" <<std::endl;
	return 0;
}

size_t add(size_t i1, size_t i2){
	return i1 + i2;
}