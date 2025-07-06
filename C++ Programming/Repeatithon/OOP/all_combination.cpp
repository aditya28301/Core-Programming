#include <cstdio>
#include <cstdlib>
#include <iostream>

class Base{
	public:
		Base(){ std::cout <<"Base class constructor is get calling = " << typeid(*this).name() << std::endl;}
			void 	inheritor(void){ std::cout <<"Base class inheritor function is called = "<< typeid(*this).name() << std::endl;}
		virtual void 	overidden_function(void) { std::cout <<"Base class overidden function is called here = " << typeid(*this).name() << std::endl; }
		
};

class Derived : public Base{
	public: 
		Derived() { std::cout <<"Derived class constructor is called here" << typeid(*this).name() << std::endl; }
		void	derived_function(void) { std::cout << "Derived function = " << typeid(*this).name() << std::endl; }
		void 	overidden_function(void) { std::cout <<"Derived overidden function =" << typeid(*this).name() << std::endl; }
};
int main(void){
	Base* pb = 0;

	std::cout <<"!!!!Base class pointer has base class object!!!!" << std::endl << std::endl;
	pb = new Base;
	pb->inheritor();

	std::cout <<"!!!!!Base class pointer has derived class object!!!!!" << std::endl << std::endl;
	pb = new Derived;
	pb->inheritor();		
	pb->overidden_function();
	if(typeid(*pb) == typeid(Derived))
		dynamic_cast<Derived*>(pb)->derived_function();

	pb->::Base::overidden_function()x;

	std::cout << "!!!!!Derived class pointer has derived specific object!!!!!" << std::endl << std::endl;
	Derived* pd = new Derived;
	pd->derived_function();
	pd->overidden_function();
	pd->inheritor();
	pd->::Base::overidden_function();	
	
	delete pd;	
	delete pb;
	std::cout <<"Programe termianted sucesfully" << std::endl;
	return EXIT_SUCCESS;
}
