#include <cstdlib>
#include <cstdio>
#include <iostream>

class hasPtr{
	private:
		int* ptr;
		int n;

	public:
		hasPtr() : ptr(0), n(0){}
		hasPtr(int n_) : ptr(new int(n_)), n(n_){}

		friend std::ostream& operator<<(std::ostream& os, const hasPtr& h){
			os <<std::endl<<*(h.ptr) << std::endl << h.n;
			return (os);
		} 
		~hasPtr(){
			free(ptr);
			ptr = 0;
		}
};

int main(void){
	hasPtr h1(10);
	hasPtr h2(h1);
	std::cout	<<"Before " <<"H1= "<< h1 << std::endl <<"H2= " << h2 <<std::endl;
	std::cout	<<"After "	<<"H1= " << h1 <<std::endl <<"H2= " << h2 <<std::endl;
	return 0;
}