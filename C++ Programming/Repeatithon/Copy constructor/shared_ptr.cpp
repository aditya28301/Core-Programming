#include <cstdio>
#include <cstdlib>
#include <memory>
#include <iostream>

void test(void);

int main(void){
	test();
	std::cout << " Programme terminated succesfully" << std::endl;
	return EXIT_SUCCESS;
}

void test(void){
	std::shared_ptr<int> p(std::make_shared<int>(10));
	std::cout << *p << std::endl;
	std::cout <<"Use count" << p.use_count() << std::endl;

	std::shared_ptr<int> p2;
	p2 = p;
	std::cout << *p2 << std::endl;
	std::cout << p2.use_count() << std::endl;

	std::cout << " reduce object count " << std::endl;
	p2.reset();
	std::cout << " Object count is = " << p2.use_count() << std::endl;
	
	std::cout << " Transfering the ownership of the object " << std::endl;
	std::shared_ptr<int> pp;
	pp = std::move(p);
	if(p == nullptr)
		std::cout << "p is not owning any ownership " << std::endl;
	std::cout << "count is = " << pp.use_count() << std::endl;
}
