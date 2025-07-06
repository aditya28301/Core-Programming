#include <cstdio>
#include <cstdlib>
#include <iostream>

void referenc_var(void);
void ref2(int& ref_1, int& ref_2);

class ref_pointer{
	private:
		int day;
		int month;
		int year;
		
	public:

		ref_pointer() : day(1), month(1), year(1997){ };
		ref_pointer& getObj(){ return *this;}
		void show() const {
			std::cout <<"Class show Member function" << std::endl; 
			std::cout <<"Day = " <<day << std::endl;
			std::cout <<"Month = " <<month << std::endl;
			std::cout <<"year = "  << year << std::endl;
		}
};

int main(void){
	referenc_var();
	int a = 100;
	int b = 200;

	ref2(a, b);	
	
	ref_pointer r1;
	ref_pointer& r2 = r1.getObj();
	r2.show();
	
	std::cout << "Ref_1 = " << a << std::endl;
	std::cout << "Ref_2 = " << b << std::endl;
	return EXIT_SUCCESS;
}

void ref_poin(int& ref_1, int& ref_2){
	std::cout <<"" << std::endl;
}

void ref2(int& ref_1, int& ref_2){
	std::cout <<"Reference Variable 1 = " << ref_1 << std::endl;
	std::cout <<"Reference Variable 2 = " << ref_2 << std::endl;

	ref_1 = 1;
	ref_2 = 2;
}

void referenc_var(void){
	int num = 100;
	int& ref = num;
	
	std::cout <<"num = " << num << std::endl;

	//Change the actual instance variable value
	ref = 200;
	std::cout <<"num = " << num << std::endl;									
}
