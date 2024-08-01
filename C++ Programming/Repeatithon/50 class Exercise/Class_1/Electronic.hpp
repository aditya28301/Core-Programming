#ifndef _ELECTRONIC_HPP_
#define _ELECTRONIC_HPP_

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <ctime>

class Electronic_Item{
	private:
		size_t item_code;
		std::string item_name;
		
	public:
		Electronic_Item(size_t code, const std::string& name) : item_code(code), item_name(name){}
		
		void dispatch(void){
			printf("item_code = %zu\n", item_code);
			std:: cout<< item_name <<std::endl <<std::endl;
		}
};
void Get_Item(Electronic_Item* ptr);
Electronic_Item* Inventory(size_t choice);
Electronic_Item* Mobile_catlog(void);
Electronic_Item* Laptop_catlog(void);

#endif
