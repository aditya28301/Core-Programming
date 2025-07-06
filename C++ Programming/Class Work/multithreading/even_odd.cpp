#include <thread>
#include <iostream>
#include <vector>

typedef void*(*cst_thread)(void*);

const int SIZE = 10;

void* thread_entry_function_1(void*);
void* thread_entry_function_2(void*);

int main(void){
	pthread_t thread1, thread2;
	std::vector<int> vec;
	for(size_t i = 0; i < SIZE; ++i){
		vec.push_back(i + 1);
	}
	
	pthread_create(&thread1, NULL, (cst_thread)thread_entry_function_1, &vec);
	pthread_create(&thread2, NULL, (cst_thread)thread_entry_function_2, &vec); 
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	std::cout <<"SUCCESS" << std::endl;
	return EXIT_SUCCESS;
}

void* thread_entry_function_1(void* arg){
	std::vector<int>& vec = *static_cast<std::vector<int>*>(arg);
	
	for(size_t i = 0; i < vec.size(); ++i){
		if(vec[i] % 2 == 0){
			std::cout << vec[i] << std::endl;
		}
	}
	return (NULL);
}

void* thread_entry_function_2(void* arg){
	std::vector<int>& vec = *static_cast<std::vector<int>*>(arg);
	
	for(size_t i = 0; i < vec.size(); ++i){
		if(vec[i] % 2 != 0){
			std::cout << vec[i] << std::endl;
		}
	}
	return (NULL);
}
