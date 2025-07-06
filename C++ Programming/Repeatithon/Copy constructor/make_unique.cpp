#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <memory>

void test(void);

int main(void){
	test();
	std::cout << " Programme terminated sucessfully" << std::endl;
	return EXIT_SUCCESS;
}

void test(void){
	std::unique_ptr<int> p(std::make_unique<int>(10));
	std::cout << *p << std::endl;
	
	std::unique_ptr<int> p1;
	p1 = std::move(p);
	if(p == nullptr)
		std::cout << "p is not owning any object ownership" << std::endl;
	std::cout << *p1 << std::endl;	
}
