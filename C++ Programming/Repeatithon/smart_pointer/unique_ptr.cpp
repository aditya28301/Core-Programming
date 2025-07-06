#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <memory>

void test(void);

int main(void){
	test();
std::cout << "Programmer terminated sucessfully " << std::endl;
	return EXIT_SUCCESS;
}

void test(void){
	std::unique_ptr<int> p(new int(10));	//It creating null ptr;
	std::cout << *p << std::endl;	
	//std::unique_ptr<int> p2(p);		// it will failed becuase unique_ptr restrict the copying the object;
	std::unique_ptr<int> a;
	//a = p;				// it will also failed beacuse unique_ptr is restricting the copy assignment operato
	p.reset(new int(20));
	std::cout <<*p << std::endl;	
	a = std::move(p);
	if(p == nullptr)
		std::cout <<"p is null" << std::endl;
	std::cout <<*a << std::endl;
}
