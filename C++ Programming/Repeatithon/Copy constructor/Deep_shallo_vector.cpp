#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

void test(void);

class Vec_ref{
	public:
		size_t* ptr;
		size_t count;
	Vec_ref() { std::cout << "Default constructor is called here" << std::endl; }
	Vec_ref(size_t size_) : ptr(new size_t[size_]), count(1) {
 	std::cout << "Vec_ref() :  Ref count default constructor is called" << std::endl; }
};

class Vector{
	private:
		Vec_ref* vec;
		size_t size;
	public:
		Vector(size_t size_) : vec(new Vec_ref(size_)), size(size_) { 
			std::cout << "Vector() : Default constructor is called" << std::endl;
			for(size_t i = 0; i < size; ++i)
				vec->ptr[i] = rand() % 100;		
		}
	
		Vector(const Vector& rhs) :  vec(rhs.vec) , size(rhs.size) {
			std::cout << "Copy constructor is called herer " << std::endl;
			vec->count += 1;
		}
		
		Vector& operator=(const Vector& rhs){
			std::cout << "Copy assignement copy constructor is called here" << std::endl;
			if(this  != &rhs){
				vec->count -= 1;
				if(vec->count == 0){
					delete vec->ptr;
					delete vec;	
				}	
				vec = rhs.vec;
				vec->count += 1;
			}
			return *this;	
		}

		~Vector() { 
			std::cout << "Destructor is called()" << std::endl;
			std::cout << "Ref = " << vec->count << std::endl;
			vec->count -= 1;
			if(vec->count == 0){
				delete[] vec->ptr;
				delete vec;
			}
		}

		friend std::ostream& operator<<(std::ostream& os, const Vector& rhs){
			os << "Printing the vector "<< std::endl;
			for(size_t i = 0 ; i < rhs.size; ++i){
				os << rhs.vec->ptr[i] << " ";		
			}	
			return os;
		}
};

int main(void){
	test();
	std::cout << " Programme terminated sucesfully" << std::endl;
	return  EXIT_SUCCESS;
}

void test(void){
	Vector v1(10);
	std::cout << v1 << std::endl;
	
	Vector v2(v1);
	std::cout << v2 << std::endl;

	Vector v3(20);
	v1 = v3;
	std::cout << v1 << std::endl;
}
