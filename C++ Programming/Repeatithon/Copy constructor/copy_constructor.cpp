#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

class Date{
	private:
		int day;
		int month;
		int year;
	
	public:
		Date() : day(1), month(1), year(2000){ std::cout << "Default constructor is called here" << std::endl;}

		Date(int _day, int _month, int _year) : 
				day(_day), month(_month), year(_year) { 
		std::cout << "Parameterised constructor is calle here" << std::endl; }

		~Date(){ std::cout << "destructor is called here" << std::endl; }
		friend std::ostream& operator<<(std::ostream& os, const Date& rhs);
};

std::ostream& operator<<(std::ostream& os, const Date& rhs){
	os << "[" << rhs.day << "," << rhs.month << "," << rhs.year << "]" << std::endl;
	return os;
}
int main(void){
	Date date1; //Default constructor
	Date date2(28, 3,2001); //Paramerterised constructor	
	std::cout <<"Synthesize copy constructor is called here" << std::endl;
	Date date3(date2);
	std::cout << date3 << std::endl;
	std::cout <<"Synthesize copy assignment operator is called here" << std::endl;
	date1 = date2;
	std::cout << date1 << std::endl;
	return EXIT_SUCCESS;
}
