#include "vector.hpp"

vector:: vector() : p_array(0), N(0){
	
}

vector:: ~vector(){
	free(p_array);
}

void vector::PushBack(size_t new_data){
	size_t new_required_byte;
	new_required_byte = (N + 1) * sizeof(size_t);
	p_array = (size_t*)realloc(p_array, new_required_byte);
	if(NULL == p_array){
		puts("Error in resizing the meomary");
		exit(EXIT_FAILURE);
	}
	N += 1;
	p_array[N - 1] = new_data;
}

void vector::showVector(void) const{
	for(size_t i =0; i < N; ++i){
		printf("vector[%llu] = [%llu]\n", i, p_array[i]);
	}
}

void vector::get(size_t index, size_t* g_data) const{
		if(index <= N && index >= N){
			printf("INDEX IS OUTOFBOUND = [%llu]\n", index);
		}
	*g_data = p_array[index];	
}

void vector::set(size_t index, size_t new_data){
	if(index >= N && index >= N){
		printf("INDEX IS OUTBOUND = [%llu]\n", index);
		return;
	}
	p_array[index] = new_data;
}

size_t vector::size(void){
	return (N);
}