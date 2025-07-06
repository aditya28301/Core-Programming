#include "Date.hpp"

Date::  Date(int _day, int _month, int _year) : day(_day), month(_month), year(_year){ } 
int Date:: get_day() const{

	return day;
}

int Date:: get_month() const{
	return month;
}

int Date:: get_year() const{
	return year;
}

IDate* IDate:: get_instance(int _day, int _month, int _year){
	return new Date(_day, _month, _year);
}

void IDate:: released_instance(IDate* pDate){
	delete dynamic_cast<Date*>(pDate);
}
