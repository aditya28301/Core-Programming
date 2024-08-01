#include <cstdio>
#include <cstdlib>

void test(void);

class Vector{

    public:

        void set(const size_t index, int data){
    
        }

        int get(const size_t index) const{
            return 1;
        }

        void show(void) const{
            // print logic will be here
        }

        int size(void) const{
            // return the vector 
            return 1;
        }

        void resize(size_t new_size) const{
            // Resize logic goes 
        }
};

int main(void){
    test();
    return 0;
}
void test(void){
    size_t new_size;
    Vector v;
    v.set(1,200);
    v.get(5);
    v.show();
    v.size();
    v.resize(10);
}