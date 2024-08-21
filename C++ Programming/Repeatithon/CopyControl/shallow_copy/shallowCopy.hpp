#pragma once
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>

struct share{
	int* ptr;
	int count;
};

class shallowCopy{
	private:
		struct share* shptr;
		std::string name;

	public:
		~shallowCopy(){
			std::cout <<"BEFORE COUNT IS "<< shptr->count <<std::endl;
			shptr->count-= 1;
			std::cout <<"AFTER COUNT IS "<< shptr->count <<std::endl;
			if(shptr->count == 0){
				free(shptr->ptr);
				free(shptr);
			}
			std::cout <<"object destroyed" <<std::endl<<std::endl;
		} 

		shallowCopy(const std::string& str, int n) : name(str), shptr(new share){
			shptr->ptr = (int*)malloc(sizeof(int));
			if(shptr == 0){
				std::cout <<"Error in allocating the meomary" <<std::endl;
				exit(EXIT_FAILURE);
			}
			shptr->count = 1;
			*shptr->ptr = n;
		}
		
		shallowCopy(const shallowCopy& rhs) : shptr(rhs.shptr), name(rhs.name){
			shptr->count+= 1;
		}

		shallowCopy& operator=(const shallowCopy& rhs){
			if(this != &rhs){
				shptr->count-= 1;
				if(shptr->count == 0){
					
					free(shptr->ptr);
					free(shptr);
				}
				shptr = rhs.shptr;
				name = rhs.name;
				shptr->count+= 1;
			}
			return *this;
		}	
		
		friend std::ostream& operator<<(std::ostream& os, const shallowCopy& rhs){
			os << "name" << rhs.name <<std::endl;
			os << "count" <<rhs.shptr->count <<std::endl;
			return os;
		}	
};


void run(void);
