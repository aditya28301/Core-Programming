#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <typeinfo>

class A{
	private:
		int day;
		int month;
		int year;
	public:
		A() : day(28), month(3), year(2001) { std::cout <<"Class A constructor is called here" << std::endl;}
		virtual void get_data(void){ std::cout <<"Day = "  << day <<"month = " << month <<"Year = " << year << std::endl; }
};

class B : public A{
	private:
		int product_day;
		int product_month;
		int product_year;
	public:
		B() : 	product_day(1), product_month(1), product_year(1) { 
			std::cout <<"Class B constructor is called here" << std::endl; }

		void 	get_data(void) { 
			std::cout 	<<"Product_day = " << product_day 
					<<"Product_month = " << product_month 
					<<"product_year = " << product_year << std::endl;
			}
};

class C:  public A{
	public:
	C() { std::cout <<"C class constructor is get calling here" << std::endl;}	
	void get_data(void){ std::cout <<"class c function is get calling here" << std::endl;}	
};

int main(void){
	srand(time(0));
	A* pb = nullptr;
	switch(rand() % 3){
		case 0:
			pb = new B;
			std::cout <<"Inside 0" << std::endl;
			break;
		case 1:
			pb = new C;
			std::cout <<"Inside 1" << std::endl;
			break;
	}

	std::cout <<"Runtime type indentification result is = " << typeid(*pb).name() << std::endl;
	std::cout <<"Function is get called here() " << std::endl;
 	pb->get_data();
	delete pb;
	std::cout <<"Programme terminated sucesfully" << std::endl;		
	return EXIT_SUCCESS;
}
