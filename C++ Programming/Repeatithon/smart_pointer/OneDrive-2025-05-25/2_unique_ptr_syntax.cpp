#include <iostream>
#include <memory>
#include <cstdio>

void unique_ptr_demo_1(); 

int main(){
	unique_ptr_demo_1();
	return 0; 
}

void unique_ptr_demo_1(){
	std::unique_ptr<int> pu1; 

	if(pu1.get() == 0)
		std::cout << "pu1 contains null" << std::endl; 	

	std::unique_ptr<int> pu2(new int(500)); 
	printf("*pu2:%d\n", *pu2); 
	pu2=nullptr; 
	if(pu2.get() == 0)
		printf("pu2 contains null\n"); 

	// release() 
	std::unique_ptr<int> pu3(new int(600)); 
	int* p_int = pu3.release(); 
	printf("*p_int:%d\n", *p_int); 

	if(pu3.get() == 0)
		printf("pu3 is null\n"); 

	delete p_int; 
	p_int = 0; 

	// reset() 
	std::unique_ptr<int> pu4(new int(700)); 
	pu4.reset(); 
	if(pu4.get() == 0)
		printf("pu4 is null\n"); 

	std::unique_ptr<int> pu5(new int(800)); 
	int* p_int1 = pu5.release();
	printf("*p_int1=%d\n", *p_int1);
	pu5.reset(p_int); 
	if(pu5.get() == 0)
		printf("pu5 is null"); 

	std::unique_ptr<int> up6(new int(500)); 
	up6.reset(new int(800)); 
}