#include <iostream>

class vector{
	private:
		int* ptr;
		int size;
	
	public:
		vector() : ptr(0), size(0){}
		vector(int n) : ptr(new int[n]) , size(n) {}

		vector(const vector& other){
			ptr = (int*)malloc(other.size * sizeof(int));
			size = other.size;
			if(ptr == 0)
				std::cout <<"Error in allocating the meomary" <<std::endl;
			memcpy((void*)ptr, (void*)other.ptr, other.size * sizeof(int));
		}

		vector& operator=(const vector& rhs){

			if(this != &rhs){
				size = rhs.size;
				ptr = (int*)realloc(ptr, size * sizeof(int));
				if(ptr == 0)
					std::cout <<"Error in resizing the meomary" <<std::endl;
				memcpy((void*)ptr, (void*)rhs.ptr, size * sizeof(int));
			}
			return *this;
		}

		void pushback(int data){
			int new_required_byte = (size + 1) * sizeof(int);
			ptr = (int*)realloc(ptr, new_required_byte);
			if(ptr == 0)
				std::cout <<"Error in allocating the meomary" <<std::endl;
			size+= 1;
			ptr[size - 1] = data;
		}

		friend std::ostream& operator<<(std::ostream& os, const vector& v){
			for(int  i = 0; i < v.size; ++i)
				os <<"["<< i <<"]: "<< v.ptr[i] << std::endl;	
			return os;
		}

		int& operator[](const int& index){
			return ptr[index];
		}

		~vector(){
			delete[] ptr;
		}

};

int main(void){
	
	vector v1(10);
	
	for(size_t i = 0; i < 10; ++i)
		v1[i] = (i + 1) * 100;

	std::cout << v1 <<std::endl;

	vector v2(v1);
	std::cout << "COPY CONSTRUCTOR v2:"<<std::endl << v2 << std::endl;

	v1.pushback(-11);
	std::cout <<"Push element ="<< -11 << std::endl << v1 <<std::endl;

	vector v3;
	v3 = v1;
	std::cout <<"opeartor assignment " <<std::endl << v3 << std::endl;

	std::cout <<"Programmer terminated succesfully" <<std::endl;
	return 0;
}