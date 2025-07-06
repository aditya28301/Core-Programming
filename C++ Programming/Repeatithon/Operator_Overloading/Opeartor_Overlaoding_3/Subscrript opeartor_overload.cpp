#include <iostream>
#include <cstdlib>

class array{
    int* ptr;
    int size;

    public:
        ~array(){
            delete[] ptr;
        }
        array(int _size) : ptr(new int[_size]), size(_size){
            std::cout <<"Constructor is called here" << std::endl;
        }
        int& operator[](int index){
            return *(ptr + index);
            
        }

        array& operator++(){
            size = size + 1;
            return *this;
        }

        array operator--(int){
            array temp(size);
            size = size - 1;
            return temp;
        }
        
        void show(){
            std::cout << size << std::endl;
        }
};

/*std::ostream& operator<<(std::ostream& os, array& rhs){
    std::cout << rhs << std::endl;
}*/


int main(void){
    array a(10);
    array result(10);
    result = ++a;   //a == 11
    result = a--;  //result = 11 and a = 10
    std::cout <<"Programe terminated sucesfully" << std::endl;

    std::cout << std::endl;
    result.show();
    return EXIT_SUCCESS;
}


/*
    (a) - *ptr =        [   ]
    a  - size 
    a = 10

    (result) - *ptr =   [   ]
    result   - size = 11


    temp =              [   ]
    size = 10
*/