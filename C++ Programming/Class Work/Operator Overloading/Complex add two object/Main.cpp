#include "complex.hpp"

int main(void){
	std::vector<int> ivec;
	std::vector<float> fvec;
	
	for(size_t i = 0; i < TEST_MAX; ++i){
		ivec.push_back(i * 100);
	}
	for(size_t i = 0; i < TEST_MAX; ++i){
		fvec.push_back(i * 100.000f);
	}
	std::cout <<"printing integer vector"<< std::endl;
	for(std::vector<int>::size_type i = 0; i != ivec.size(); ++i){
		std::cout <<"vector=" << i << ivec[i]<<std::endl;
	}
	
	for(std::vector<float>::size_type i = 0; i != fvec.size(); ++i){
		std::cout <<"vector=" << i << fvec[i]<<std::endl;
	}
	
	complex c1;
	complex c2(100.00f, 200.0f);
	complex sum;
	sum = c1.add(c2);
	sum.show("Addition of as per below");
	return 0;
}