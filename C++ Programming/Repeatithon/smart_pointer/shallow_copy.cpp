#include <iostream>

class shared_resources{
	friend class hasPtr;
	friend std::ostream& operator<<(std::ostream& os, shared_resources& rhs);
	private:
		int *ptr;
		int count;
	public:
		shared_resources(size_t _size): ptr(new int[_size]){
			std::cout <<"shared_resources::sharead Resources created" << std::endl;
		}
	
		~shared_resources(){	
			std::cout <<"shared_resources::No ownership found" << std::endl;
			delete[] ptr;
			ptr = 0;
		}
};

class hasPtr{
	friend std::ostream& operator<<(std::ostream& os, hasPtr& rhs);
	private:
		shared_resources* sr;
		int size;
	public:
		hasPtr(size_t _size) : sr(new shared_resources(_size)), size(_size)  { 
			std::cout <<"hasPtr::New Object created" << std::endl;
		}

		~hasPtr(){
			sr->count -= 1;
			if(sr->count == 0){
				free(sr->ptr);
				free(sr);
			}
		}
		void set(){
			for(size_t i = 0; i < size; ++i){
				sr->ptr[i] = (i + 1);
			}	
		}

};

std::ostream& operator<<(std::ostream& os, shared_resources& rhs){
 for(size_t i = 0; i < 10; ++i){
 	os << rhs.ptr[i] <<" ";
 }
  return os;
}

std::ostream& operator<<(std::ostream& os, hasPtr& rhs){
	os << *(rhs.sr);
        return os;
}

int main(void){
	
	hasPtr obj1(10);
	obj1.set();
	hasPtr obj2(obj1);
	std::cout << obj2 << std::endl;
	std::cout << obj1 << std::endl;
	std::cout <<"Programe terminated succesfull" << std::endl;
	return EXIT_SUCCESS;
}
