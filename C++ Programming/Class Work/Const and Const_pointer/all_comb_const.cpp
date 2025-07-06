#include <cstdio>
#include <cstdlib>
#include <iostream>

class pointer{
	private:
		int day;
		int month;
		int year;

	public:
		void getDay(void) const {
			std::cout <<"You can read the data but you cannot be modify the data" << std::endl;
			//day = 1000;	//  Error you cannot be modify the class data
		}
		
		void getMonth(void) const {	

		}

		void getYear(void) const { 
		
		}
};

void point_comb(void){
	//changinig pointee value via pointer
	int a = 100;
	int b = 200;

	int* ptr = &a;
	*ptr = 300;

	std::cout <<"*ptr =" << *ptr <<std::endl;

	// pointer to const	
	const int* ptr_1 = &a;
	//*ptr_1 = 200;	// Error can not be write on "a" via ptr_1
	
	int const* ptr_2 = &b;
	//*ptr_2 = 500;	// Error can not be write on "b" via ptr_2

	//const pointer 
	int* const ptr_3 = &a;	// You can write on "a" via ptr_3 but you can change the pointer address
	*ptr_3 = 500;		// Allow
	//ptr_3 = &b;		// Error 

	// const pointer to const

	const int* const ptr_4 = &b;	// Herer you cannot write on pointee via ptr_5 pointer and also you can change the address wh						ch stored on ptr_4
	b = *ptr_4;
	//*ptr_4 = &a;			// Error you can not changes the pointer stored address
	//*ptr_4 = 1000;		// Error you can not chnage the pointee via ptr_4
			
}

int num = 100;
const int gc_num = 200;

void advance_pointer_comb(void){
	int l_num = 1000;
	const int lc_num = 2000;

	int* ptr = &num;	
	*ptr = 150;	// Allow
	std::cout <<"*ptr = &num = " << *ptr << std::endl;
	std::cout <<"num = " << num << std::endl;

	ptr = &l_num;
	*ptr = 1500;
	std::cout <<"*ptr = " << *ptr <<std::endl;
	std::cout <<"l_num = " << l_num << std::endl;
	
		
	//*ptr = &lc_num;	// Errror you can assigned const int* -> int* 
	//*ptr = &gc_num;


	const int* ptr_1 = &l_num;
	//*ptr_1 = 20;	//Error you cannot be modify the pointee

	ptr_1 = &num;
	//*ptr = 20;	//Error you cannot be modify the pointe		

	ptr_1 = &gc_num;
	//*ptr_1 = 300;	// Error you cannot be modify the pointee

	int* const ptr_2 = &l_num;
	*ptr_2 = 1;
	std::cout <<"*ptr_2 = " << *ptr_2 << std::endl;			
	std::cout <<"l_num = " << l_num << std::endl;

	int* const ptr_3 = &num;
	*ptr_3 = 2;
	std::cout <<"*ptr_2 = " << *ptr_3 << std::endl;		
	std::cout <<"num = " << num << std::endl;

	const int* const ptr_4 = &num;
	const int* const ptr_5 = &num;
	const int* const ptr_6 = &lc_num;
	const int* const ptr_7 = &gc_num;	
		
}

int main(void){
	point_comb();
	advance_pointer_comb();
	return EXIT_SUCCESS;
}
