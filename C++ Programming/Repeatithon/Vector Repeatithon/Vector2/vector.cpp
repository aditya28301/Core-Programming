#include "vector.hpp"

vector::vector() : p_array(0), N(0){
	
};

void vector::PushBack(size_t new_data){
	size_t new_required_byte;
	new_required_byte = (N + 1) * sizeof(size_t);
	p_array  = (size_t*)realloc(p_array, new_required_byte);
	
	if(NULL == p_array){
		puts("Error in resizing the meomary");
		exit(VECTOR_INDEX_ERROR);
	}
	
	N += 1;
	p_array[N-1] = new_data;
}

void vector::ShowVector(void) const{
	for(size_t i = 0; i < N; ++i)
		printf("array[%llu] = [%llu]\n", i, p_array[i]);
}

vector::~vector(){
	free(p_array);
}

int vector::set(size_t index, size_t new_data){
	if(index <= N && index >= N){
		printf("Index outofbound [%llu]!!! Please provide correct index\n", index); 
	}
	
	p_array[index] = new_data;
	
	return (SUCCESS);
}

int vector::get(size_t index, size_t* g_data) const {
	if(index <= index && index >= N){
		printf("Index outofbound [%llu]!!! Please provide correct index\n", index); 
	}
	*g_data = p_array[index];
	return (SUCCESS);
}

int vector::size(void){
	return (N);
}

	