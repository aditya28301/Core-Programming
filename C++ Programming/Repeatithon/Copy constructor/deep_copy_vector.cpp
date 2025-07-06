#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

class Vector{
	private:
		int* ptr;
		int N;
	public:
		~Vector() { std::cout << "Calling destructor" << std::endl; delete[] ptr; }

		Vector() : ptr(0), N(0){  std::cout << " Object is initialized" << std::endl; }
 
		Vector(const Vector& rhs) : ptr(new int[rhs.N]) , N(rhs.N){
			for(size_t i = 0 ; i < rhs.N; ++i){
				ptr[i] = rhs.ptr[i];	
			}
			if(rhs.N != 0)
				std::cout <<"Object is sucessfully copying" << std::endl;
		} 

		Vector& operator=(const Vector& rhs){
			if ( this == &rhs) return *this;
			delete[] ptr;
			ptr = new int[rhs.N];
			for(size_t i = 0; i < rhs.N; ++i)
				ptr[i] = rhs.ptr[i];
			if(rhs.N != 0)
				std::cout <<"Object is succesfully coiped" << std::endl;
			
			return *this;
		}

		void push_back(int data){
			size_t new_required_byte = (N + 1) *  sizeof(int);
			ptr = (int*)realloc(ptr, new_required_byte);
			if(ptr == 0){
				std::cout <<"Error in allocating the meomary" << std::endl;
				exit(EXIT_FAILURE);
			}
				
			N  = N + 1;
			ptr[N-1] = data;
		}

		friend std::ostream& operator<<(std::ostream& os, const Vector& rhs){
			os << "Printing vector" << std::endl;
			for(size_t i = 0; i < rhs.N; ++i){
				os << rhs.ptr[i] <<" ";
			}			
			return os;
		}
};

int main(void){

	Vector* v1 = new Vector;
	v1->push_back(10);
	v1->push_back(20);	
	std::cout << *v1 << std::endl;
	
	Vector v2(*v1);
	std::cout << v2 << std::endl;

	*v1 = v2;
	std::cout << *v1 << std::endl;
	delete v1;
	v1 = 0;
	return EXIT_SUCCESS;
}
