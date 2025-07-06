#include <cstdio>
#include <cstdlib>
#include <iostream>

class test{
	friend void getAcess(void);
	friend class test2;
	private:
		int day;
		int month;
		int year;


	protected:

		int d;
		int m;
		int y;
	
	public:
		test() :  day(1), month(1), year(2001), d(10), m(10), y(2001) { std::cout <<"#" << std::endl; }

		void show(){
			std::cout <<"day = " << day <<"/" << "Month = " << month << "Year = " << year << std::endl;
		}
};


class test2{
	private:
		std::string name;

	public:
		test2() { std::cout <<"#" << std::endl;}
		void getAcessTest() {
			test t1;
			std::cout <<"Day = " << t1.day <<std::endl << t1.month << std::endl << t1.year << std::endl; 


			std::cout <<"Accessing the protected the memebre from the class test1" << std::endl;
			std::cout <<"d = " << t1.d <<"m = " << t1.m << "y = " << t1.y << std::endl;
		 } 		

		static void generic_function() {
			test2 t2;
			t2.getAcessTest();
		}
};

void getAcess(void){
	test t1;
	std::cout <<"t1.Day = " << t1.day <<std::endl <<"t1.month = " << t1.month <<std::endl <<"t1.year = " << t1.year << std::endl;	
}

int main(void){
	getAcess();
	test2::generic_function();
	return EXIT_SUCCESS;
}
