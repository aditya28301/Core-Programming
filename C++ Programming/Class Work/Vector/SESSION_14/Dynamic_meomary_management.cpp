#include <cstdio>
#include <cstdlib>

#define TEST_MAX 10

void test(void);

class Vector{
    private:
        size_t* arr;
        size_t N;

    public:
        Vector() : arr(0), N(0){};

    void PushBack(size_t data){
        size_t new_required_byte;
        new_required_byte = ((N + 1) * sizeof(size_t));
        arr = (size_t*)realloc(arr, new_required_byte);
        if(NULL == arr){
            puts("Error in allocating the meomary");
            exit(EXIT_FAILURE);
        }

        N += 1;
        arr[N - 1] = data;
    }

    void ShowVector(){
        for(size_t i = 0; i < N; ++i){
            printf("Vector[%llu] = [%llu]\n", i, arr[i]);
        }
    }

    ~Vector() {
        free(arr);
    }

};

int main(void){
    test();
    return 0;
}

void test(void){
    Vector* pvector = new Vector;
    for(size_t i = 0; i < TEST_MAX; ++i){
        pvector->PushBack(i * 100 + 1);
    }
    pvector->ShowVector();
    delete pvector;
    pvector = 0;
    puts("Terminated Successfully");
}  