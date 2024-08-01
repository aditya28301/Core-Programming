#include "vector.hpp"
#define TEST_MAX 10
void test(void);

int main(void){
    test();
    return 0;
}

void test(void){
    size_t data;
    int status;

    vector* pvector = new vector;
    for(size_t i = 0; i < TEST_MAX; ++i){
        pvector->Push_Back(i * 100 + 1);
    }
    pvector->Show_Vector("SHow Vector");

    status = pvector->get(pvector->size(), &data);
    if(status == VECTOR_INDEX_ERROR)
        puts("Index bound is overridden");

    status = pvector->get(pvector->size() - 1, &data);
    if(status == SUCCESS)
        printf("LAST ELEMENT = [%llu]\n", data);

    delete pvector;
    pvector = 0;
    puts("Terminated Successfully");
}