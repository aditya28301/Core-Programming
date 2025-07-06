#include <iostream>
#include <cstdlib>

class array{
    private:      
        int* ptr;
        int size;

    public:
        array(int _size) :  ptr(new int[_size]), size(_size){   
            std::cout <<"Constructor is called here" << std::endl;
        }

        ~array(){
            delete[] ptr;
        }
};
int main(void){
    array a(10);
    return EXIT_SUCCESS;
}
