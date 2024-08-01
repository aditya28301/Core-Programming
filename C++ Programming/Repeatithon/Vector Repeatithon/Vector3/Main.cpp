#include "vector.hpp"

#define TEST_MAX 100

int main(void){
	vector* pvector = new vector;
	size_t g_data;
	for(size_t i = 0; i < TEST_MAX; ++i)
		pvector->PushBack(i * 100);
	
	pvector->showVector();
	
	pvector->set(1000, 0);
	
	pvector->get(50, &g_data);
	
	printf("size of vector array is = [%llu]\n", pvector->size());
	
	delete pvector;
	pvector = 0;
	
	puts("Programme terminated succesfully");
	return (EXIT_SUCCESS);
}