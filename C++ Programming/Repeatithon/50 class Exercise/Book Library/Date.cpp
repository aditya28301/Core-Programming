#include "Date.hpp"

Date::Date(size_t i_day, size_t i_month, size_t i_year):
day(i_day), month(i_month), year(i_year){

}

std::ostream& operator<<(std::ostream& os, const Date& objdate){
    std::cout << "Manufature Day = " << objdate.day << std::endl;
    std::cout << "Manufacture month =  " << objdate.month << std::endl;
    std::cout << "Manufature Year = " << objdate.year << std::endl;
    return os;
}