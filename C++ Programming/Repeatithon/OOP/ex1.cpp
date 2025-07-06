#include <cstdio>
#include <cstdlib>
#include <iostream>

//Class defination of pointer 



//Class defination of pointer
class pointer{
	private:
		int day;
		int month;
		int year;

	public:
		pointer() { }
		void getDay() const { 
			std::cout <<"Day = " << day << std::endl;
		}
			 
		//Here you cant change object of instance
		void getMonth() const { std::cout <<"Month = " << month << std::endl; } 
		void getYear() const { std::cout << "year = " << year << std::endl; }
};

int main(void){
//pointer to const defination
int num = 10;
int num2 = 20;

int* ptr = &num;
const int* c_ptr = &num;
c_ptr = &num2;

std::cout <<"pointer to const" << *c_ptr << std::endl;

//const pointer to int
int p_num = 100;
int* const const_ptr = &p_num;
std::cout << "const pointer to int" << *const_ptr << std::endl;
	return EXIT_SUCCESS;
}

// const pointer to const

int p_num2 = 200;
const int* const ptr_3 = &p_num2;
std::cout <<"Const pointer to const" << *ptr_3 << std::endl;

//pointer class pointer created + object of pointer class created and assigned
pointer* p1 = 0;
p1 = new pointer;

p1->getDay();	//class getDay function call here

return EXIT_SUCCESS;
