#include <cstdio>
#include <cstdlib>
#include <iostream>


int main(void){
	
	int* ptr = (int*)malloc(5 * sizeof(int));
	
	if(ptr == NULL){
		std::cout <<"Meomary allocation failed" << std::endl;
	}
	
	for(size_t i =0 ; i < 5; ++i){
			
		ptr[i] = i * 10;
	}

	// Not freeing the meomary occured meomary leak
	return EXIT_SUCCESS;
}
