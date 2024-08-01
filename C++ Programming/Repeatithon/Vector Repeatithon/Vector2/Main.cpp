#include "vector.hpp"

#define TEST_MAX 10

int main(void){
	vector* pvector = new vector;
	size_t g_data;
	for(size_t i = 0; i < TEST_MAX; ++i)
		pvector->PushBack(i * 100);
	
	pvector->ShowVector();
	
	pvector->get(3, &g_data);
	pvector->set(100, 999);
	
	delete pvector;
	pvector = 0;
	puts("Code Terminated Succesfully");
	return (EXIT_SUCCESS);
}