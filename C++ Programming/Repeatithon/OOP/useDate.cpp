#include "IDate.hpp"

int main(void){
	IDate* pDate = IDate::get_instance(28, 3, 2001);
	std::cout <<"Get_day=" << pDate->get_day() << std::endl;
	std::cout <<"Get_month=" << pDate->get_month() << std::endl;
	std::cout <<"Get_year=" << pDate->get_year() << std::endl;

	//Error 
	//pDate->::IDate::get_day();	// Error		
	IDate::released_instance(pDate);
	std::cout <<"Programe terminated succesfully" << std::endl;	
	return EXIT_SUCCESS;
}

