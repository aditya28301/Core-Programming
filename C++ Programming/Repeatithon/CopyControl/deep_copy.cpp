#include <iostream>

class copy_resource{
	friend std::ostream& operator<<(std::ostream& os, copy_resource& rhs);
	friend class Hasptr;
	private:
		int* ptr;
		int size;

	public:
		copy_resource(size_t _size) : ptr(new int[_size]), size(_size){ 
			std::cout <<"copy resources created" << std::endl;
		}
	
		~copy_resource(){
			free(ptr);
			ptr = 0;
		}
};

class hasPtr{
	friend std::ostream& operator<<(std::ostream& os, hasPtr& rhs);
	private:
		copy_resources cr;

	public:
		hasPtr(size_t _size) : cr(_size) {
			std::cout <<"hasPtr object is created" << std::endl;
		}

		void set(){
			for(size_t i = 0; i < cr.size(); ++i){
				cr.ptr[i] = (i + 1);
			}
		}
};

friend std::ostream& operator<<(std::ostream& os, hasPtr& rhs){
	os << rhs.cr << std::endl;
}

friend std::ostream& operator<<(std::ostream& os, copy_resource& rhs){
	for(size_t i =0 ; i < rhs.size; ++i){
		os << rhs.ptr[i] << std::endl;	
	}
}

int main(void){
	hasPtr obj1(10);
	obj.set();
	std::cout << obj << std::endl;
	return EXIT_SUCCESS;
}
