#include <cstdio>
#include <cstdlib>
#include <iostream>

template<typename T>
class vector{
	private:
		T* arr;
		size_t N;

	public:
		~vector(){
			free(arr);
			arr = 0;
		}

		vector() : arr(0), N(0){ } 

		void push_back(T data){
			
			size_t required_byte = (sizeof(T) * (N + 1));
			
			arr = (T*)realloc(arr,required_byte);
			
			if(arr == 0){
				std::cout <<"Error in allocating the meomary" << std::endl;
				exit(EXIT_FAILURE);
			}

			N = N + 1;
			arr[N - 1] = data;		
		}	

		size_t size(){
		
			return N;
		}

		void show(){
			
			for(size_t i = 0; i < size(); ++i){
				std::cout << arr[i] << std::endl;
			}
		}
};

int main(void){

	vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	
	vector<float> vec_float;

	vec_float.push_back(100.90);
	vec_float.push_back(200.20);
	
	std::cout <<"INT vector show data" << std::endl;
	vec.show();
	std::cout <<"FLOAT vector show data" << std::endl;
	vec_float.show();
	std::cout << std::endl;
	std::cout <<"Programe terminated succesfully" << std::endl;
	
	return EXIT_SUCCESS;
}















