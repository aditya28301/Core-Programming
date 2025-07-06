#include <iostream>

class IDate{

	public:
		virtual int get_day() const = 0;
		virtual int get_month() const = 0;
		virtual int get_year() const = 0;
		static IDate* get_instance(int _day, int _month, int _year);
		static void released_instance(IDate* pDate);
};
