#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

class Date{
	private:
		int* day;	
		int month;
		int year;
	public:	
	Date() : day(new int(10)), month(11), year(24) { std::cout << " Calling default constructor " << std::endl; }  
	~Date() { std::cout << "Calling destructor" << std::endl; delete day; }
	
	friend  std::ostream& operator<<(std::ostream& os, const Date& rhs){
		os << *(rhs.day) << std::endl;
		os << rhs.month  << std::endl;
		os << rhs.year   << std::endl;	
		return os;
	}
};

int main(void){

	Date date1;
	std::cout << "Calling synthetic copy constructor" << std::endl;
	Date date3(date1);
	std::cout <<date3 << std::endl;
	std::cout <<"Calling Destructor " << std::endl;
	return EXIT_SUCCESS;
}
