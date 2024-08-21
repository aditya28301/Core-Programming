#include "shallowCopy.hpp"

void run(void){
	std::cout <<"new instance of shallowCopy created DONE" <<std::endl
			  <<"automatic call to constructor DONE" <<std::endl
			  <<"address is stored in sh1 pointer DONE" <<std::endl;
	shallowCopy* sh1 = new shallowCopy("objet1", 10);
	std::cout <<"sh1 object is= " << *sh1 <<std::endl;
	std::cout <<"-------------------------------------------------------------" <<std::endl;

	std::cout <<"new instance of shallowCopy created DONE" <<std::endl
			  <<"automatic call to Copy constructor DONE" <<std::endl
			  <<"address is stored in sh2 pointer DONE" <<std::endl;
	shallowCopy* sh2 = new shallowCopy(*sh1);
	std::cout <<"sh2 object is= " << *sh2 << std::endl;
	std::cout <<"-------------------------------------------------------------" <<std::endl;

	std::cout <<"new instance of shallowCopy created DONE" <<std::endl
			  <<"automatic call to constructor DONE" <<std::endl
			  <<"address is stored in sh3 pointer DONE" <<std::endl;
	shallowCopy* sh3 = new shallowCopy("object3", 10);
	std::cout <<"sh3 object is= " << *sh3 <<std::endl;
	std::cout <<"-------------------------------------------------------------" <<std::endl;

	std::cout <<"new instance of shallowCopy created = DONE" <<std::endl
			  <<"automatic call to Copy constructor = DONE" <<std::endl
			  <<"address is stored in sh4 pointer DONE" <<std::endl;
	shallowCopy* sh4 = new shallowCopy(*sh3);
	std::cout <<"sh4 object is= " << *sh4 <<std::endl;
	std::cout <<"-------------------------------------------------------------" <<std::endl;

	
	std::cout <<"sh1 = sh2" <<std::endl;
	*sh1 = *sh2;
	std::cout <<"sh1 object is= " << *sh1 <<std::endl;

	delete sh1;
	sh1 = 0;

	delete sh2;
	sh2 = 0;
	
	delete sh3;
	sh3 = 0;

	delete sh4;
	sh4 = 0;
}