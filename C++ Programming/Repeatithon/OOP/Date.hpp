#include "iDate.hpp"

class Date :  public IDate{
	
	private:
		int day;
		int month;
		int year;

	public:
		Date(int _day, int _month, int _year);
		int get_day() const;
		int get_month() const;
		int get_year() const;	
};
