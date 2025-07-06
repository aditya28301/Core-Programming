#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <typeinfo>

class base{
	
	private:
		int item_count;
		std::string item_name;
		
	public:
		base() : item_count(0), item_name("nothing"){ std::cout <<"Base:: default constructor is called here" << std::endl;}\
		base(int _count, std::string _name) : item_count(_count), item_name(_name) { std::cout <<"Base: Parameterised constructor is called here" << std::endl;}

		void get_count() const{
			std::cout <<"class name =" << typeid(this).name() << std::endl;
			std::cout <<"Base:: inheritor function is define here" << std::endl;
			std::cout <<"item_name =" << item_count << std::endl;
		}	

		void get_name() const{
			std::cout<<"class name =" << typeid(*this).name() << std::endl;
			std::cout <<"Base:: non_virtual overidden function define here" << std::endl;
			std::cout <<"Get_name=" << item_name << std::endl;
		}

		virtual void getAll() const{
			std::cout <<"class name=" << typeid(*this).name() << std::endl;
			std::cout <<"Base:: virtual overidden function define here" << std::endl;		
			std::cout <<"item_name=" << item_name <<"item_count=" << item_count << std::endl;			
		}
};

class derived : public base{
	
	private:
	
		int price;

	public:
		derived() : base(), price(0){ std::cout <<"Derived:: default constructor is caller here" << std::endl;}

		derived(int _price) : base(10, "Apple"), price(_price) { std::cout <<"Derived:: parameterised constructor is called here" << std::endl; }

		void get_price() const { 
			std::cout <<"class name=" << typeid(*this).name() << std::endl;
			std::cout <<"Derived:: Derived specific function is called here" << std::endl; 
			std::cout <<"Price=" << price << std::endl;
			}
	
		void get_name() const { 
			std::cout <<"class name=" << typeid(*this).name() << std::endl;
			std::cout <<"Derived:: overidden non_virtual function is called here" << std::endl;
			std::cout <<"Device_name=" <<"Samusng" <<"Price=" << price << std::endl;
		}
		
		void getAll() const{
			std::cout <<"class name=" << typeid(*this).name() << std::endl;
			std::cout <<"Derived:: Derived overidden virtual function is called" << std::endl;
			std::cout <<"Device_name=" <<"Samsung" <<"Price=" << price << std::endl;
		}
};

int main(void){

	derived* d = new derived(100);
	
	std::cout << std::endl;
	
	d->get_count(); 		// inheritor->			base::get_count(&base);
	std::cout << std::endl;
	d->get_price();			// derived-> 			derived::get_price(&base);
	std::cout << std::endl;
	d->get_name();			// derived overidden-> 		derived::get_name(&derived):
	std::cout << std::endl;
	d->::base::get_name(); 		// base overidden->   		base::get_name(&base);
	std::cout << std::endl;
	d->getAll();			// derived virtual overidden->	derived::getAll(&derived);
	std::cout << std::endl;
	d->::base::getAll();		// base virtual overidden->	base::getAll(&base);
	
	std::cout << std::endl;

	base* b = new derived(200);
	
	std::cout << std::endl;

	b->get_count();					// inheritor->			base::get_count(&base);
	std::cout << std::endl;
	dynamic_cast<derived*>(b)->get_price();		// Derived->			derived::get_price(&derived);
	std::cout << std::endl;
	b->get_name();					// base overidden		base::get_name(&base);				
	std::cout << std::endl;
	dynamic_cast<derived*>(b)->get_name();		// derived overiden		derived::get_name(&derived);
	std::cout << std::endl;
	b->getAll();					// derived virtual overidden	derived::getAll(&derived);		
	std::cout << std::endl;
	b->::base::getAll();				// base virtual overidden	base::getAll(&base);
	std::cout << std::endl;
	std::cout <<"-----------------------------------Programe terminated succesfully-----------------------------------------------------------" << std::endl;
	return EXIT_SUCCESS;
}















