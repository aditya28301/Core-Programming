#include <cstdlib>
#include <cstdio>
#include <iostream>

class vector{
	private:
		size_t size;
		size_t* arr;
	public:
		vector() : size(0), arr(0) { std::cout <<"Empty vector is initialised" << std::endl; } 
		~vector(){
			free(arr);
			arr = 0;
			std::cout <<"Vector succesfully deleted" << std::endl;
		}

		void push_back(size_t num){
			size_t new_required_byte = ((size + 1) * sizeof(size_t));
			arr = (size_t*)realloc(arr, new_required_byte);

			if(arr == 0)
				EXIT_FAILURE;

			size = size + 1;
			arr[size - 1] = num;
			//std::cout <<"Element sucessfully insert = " << num << std::endl;			
		}
		
		void pop_back(){
			size_t new_required_byte = ((size - 1) * sizeof(size_t));
			arr = (size_t*)realloc(arr, new_required_byte);
			
			if(arr == 0)
				EXIT_FAILURE;

			size  = size - 1;
			//std::cout <<"Element delete" << std::endl;	
		}
		
		void show(void){
		
			for(size_t i = 0; i < size; ++i){
				std::cout << arr[i] << std::endl;
			}
		}
};

int main(void){
	
	vector* v1 = new vector;

	v1->push_back(10);
	v1->push_back(20);
	v1->push_back(30);
	v1->show();
	v1->pop_back();
	std::cout <<"Element is succesfully pop_out = " << std::endl;
	v1->show();
		
	delete v1;
	std::cout <<"Programmer terminated succesfully" << std::endl;
	return EXIT_SUCCESS;
}
