#include "complex.hpp"

complex::complex() :real(0.0), img(0.0) {}
complex::complex(float real_, float img_) : real(real_), img(img_){

}
	
complex complex::add(complex second_number){
	complex sumation;
	sumation.real = this->real + second_number.real;
	sumation.img = this->img + second_number.img;
	return sumation;
}

void complex::show(const char* msg) const{
	puts(msg);
	printf("real[%.3llf] + img[%.3llf]\n", real, img);
}


