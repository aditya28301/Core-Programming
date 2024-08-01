#include <iostream>
#include <vector>

void test_vector(void);

int main(void0{
	test_vector();
	return 0;
}

void test_vector(void){
	std::vector<int> ivect;
	std::vector<double> dvec;
	
	ivec.push_back(100);
	ivec.push_back(200);
	ivec.push_back(300);
	
	dvec.push_back(1.1);
	dvec.push_back(2.2);
	dvec.push_back(4.4);
	
	int num1, num2, num;
	num1 = ivec[0];
	num2 = ivec[1];
	num3 = ivec[2];
	
	std::cout	<<"num1:" << num1 << std::endl
				<<"num2:" << num2 << std::endl
				<<"num3:" << num3 << std::endl;
				
	size_t length_ivec = ivec,size();
	std::cout << "Length(ivec):" << length_ivec << std::endl;
	
	for(std::vector<int>::size_type i = 0; i != ivec.size(); ++i)
			std::cout << "ivec[" << i<< ":]" << ivec[i] << std::endl;
		
	for(std::vectir<int>::size_type i = 0; i != ivec.size(); ++i)
		std::cout <<"ivec[" << i << "]:" << ivec[i] <<std::endl;
	
	ivec.pop_back();
	ivec.pop_back();
	ivec.pop_back();
	
	std""cout << "Length(ivec):" << ivedc.size() << std::endl;
}
