#include <iostream> 
#include <cstdlib> 
#include <cassert> 

class array{
    private: 
        int* pa; 
        size_t size; 

    public: 
        array(size_t arr_size)
        {
            assert(arr_size > 0); 
            pa = new int[arr_size]; 
            size = arr_size; 
        }

        array(const array& other) = delete; 
        array& operator=(const array& other) = delete; 

        array(array&& other)
        {
            pa = other.pa; 
            size = other.size; 
            other.pa = 0; 
            other.size = 0; 
        }

        array& operator=(array&& other)
        {
            delete[] pa; 
            size = 0; 
            pa = other.pa; 
            size = other.size; 
            other.pa = 0;  
            other.size = 0; 
            return *this;
        }

        void resize(size_t nr_elements)
        {
            // resize according to size & nr_elements 
        }

        int at(size_t index)
        {
            assert(index >= 0 && index < size); 
            return pa[index]; 
        }

        void set(size_t index, int element)
        {
            assert(index >= 0 && index < size); 
            pa[index] = element; 
        }

        ~array()
        {
            delete[] pa; 
            pa = 0; 
            size = 0; 
        }
}; 

int main(void)
{
    array A1(5); 
    array A2(10); 

    std::cout << "here1" << std::endl; 
    for(size_t i = 0; i < 5; ++i)
        A1.set(i, (i+1)*5); 

    std::cout << "here2" << std::endl; 

    for(size_t i = 0; i < 10; ++i)
        A2.set(i, (i+1)*10); 

 
    std::cout << "here3" << std::endl; 
    array A3(std::move(A1));    

    A2 = std::move(A3); 

    // std::cout << "here4" << std::endl; 
    //int n = A1.at(0); 
    
    return (0); 
}
