#pragma once

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>
#include <thread>
#include <chrono>

const size_t itemCount = 10;

class personalcare{
	private:
		std::string product_name;
		size_t u_id;

	public:
		personalcare () : product_name(""), u_id(0){
			srand(time(0));
		}
		personalcare (std::string name) : product_name(name){
		}
		
		friend std::ostream& operator<<(std::ostream& os, const personalcare& cart){
			os <<"NAME OF PRODUCT= " << cart.product_name << std::endl <<"UNIQUE ID= " << cart.u_id << std::endl;
			return os;
		}

		void set(char* name){
			product_name = name;
			u_id = rand();
		}
		
};	

void run(void);
char** get_inventory(size_t& size);
void addItem(personalcare* slot, char** list,  size_t& size);
void print(personalcare* slot, size_t& size);
void print_with_delay(const personalcare& item, int delay_ms);