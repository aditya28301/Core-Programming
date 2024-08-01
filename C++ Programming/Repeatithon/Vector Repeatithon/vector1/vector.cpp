#include "vector.hpp"

vector::vector() : p_array(0), N(0){

}

vector::~vector(){
    free(p_array);  
}

void vector::Push_Back(size_t new_data){
    size_t new_required_byte;
    new_required_byte = ((N + 1) * sizeof(size_t));
    p_array = (size_t*)realloc(p_array, new_required_byte);
    if(p_array == NULL){
        puts("Error in resizing the meomary");
        exit(EXIT_FAILURE);
    }
    N += 1;
    p_array[N - 1] =  new_data;
}

void vector::Show_Vector(const char* msg) const{
    if(msg != 0)
        puts(msg);

    for(size_t i = 0; i < N; ++i)
        printf("ARRAY[%llu] = [%llu]\n", i, p_array[i]);
}

int vector::get(size_t index, size_t* p_data) const {
    if(index < 0 || index >= N)
        return VECTOR_INDEX_ERROR;
    *p_data = p_array[index];

    return SUCCESS;
}
void vector::set(size_t index, size_t new_data){
    p_array[index] = new_data;
}

int vector::size(void) const{
    return N;
}