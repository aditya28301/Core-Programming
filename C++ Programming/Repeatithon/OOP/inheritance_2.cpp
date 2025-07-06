#include <cstdio>
#include <cstdlib>
#include <iostream>

class base{

	private:
		int day;
		int month;
		int year;

	public:
		base() : day(1), month(1), year(2001){  std::cout <<"Base class default constructor is called here" << std::endl;}
		base(int _day, int _month, int _year) : day(_day), month(_month), year(_year){
		
			std::cout <<"Base Parameterised constructor is calle here" << std::endl;
		}
			
		inline int get_day() const{
			return day;
		}

		int get_month() const{
			return month;
		}	

		int get_year() const{
			return year;
		}
};

class derived : public base{

	private:
		int time;	
	public:
		derived() : time(0) { std::cout <<"Derived class default constructor is called here" << std::endl;}
		derived(int _time) : base(-1, -1, -1), time(_time){
	
			std::cout<<"Derived class paramterised constructor is called here" << std::endl;
		}
		inline int get_time() const{
			return time;	
		}	
};


int main(void){

	derived* d1 = new derived(10);
	
	std::cout <<"base class : day = " << d1->get_day() << std::endl;
	std::cout <<"derived class : time = " << d1->get_time() << std::endl;
	
	std::cout <<"Programe terminated succesfully" << std::endl;
	return EXIT_SUCCESS;
}
