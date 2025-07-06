#include <iostream> 

class Date{
    private: 
        int day, month, year; 
    public: 
        Date() = default;                   // inline 
        Date(const Date& other) = default;  // inline 
        ~Date() = default;                  // inline 
        Date& operator=(const Date &other); 
        Date(int init_day, int init_month, int init_year) : day(init_day), month(init_month), year(init_year) {}
}; 

Date& Date::operator=(const Date &other) = default; // non-inline 

int main(void)
{
    Date d1(10, 2, 2021);   // parameterized constructor 
    Date d2;                // inline default constructor 
    Date d3(d1);            // inline copy constructor 
    d2 = d1;                // non-inline assignment overload operator 

    return (0);
}