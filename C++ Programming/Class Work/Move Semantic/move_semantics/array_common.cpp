#include <iostream> 
#include <cstdlib> 
#include <utility> 

class Date
{
    private: 
        int day, month, year; 
    public: 
        Date(int init_day, int init_month, int init_year) : day(init_day), month(init_month), year(init_year) {} 
        Date() : day(1), month(1), year(1970) {} 
        void show() const { std::cout << day << "-" << month << "-" << std::endl;  }
};  

template <typename T> 
class array
{
    private: 
        T* pa; 
        size_t size; 
    public: 
        array(size_t arr_size) : 
        {
            assert(arr_size > 0); 
            pa = new T[arr_size]; 
            size = arr_size; 
        }

        T at(size_t index)
        {
            assert(index >= 0 && index < size); 
            return pa[index]; 
        }

        T&& at(size_t index)
        {
            assert(index >= 0 && index < size); 
            return pa[index]; 
        }

        void set(size_t index, T* element)
        {
            assert(index >= 0 && index < size); 
            pa[index] = element; 
        }

        void set(size_t index, T&& element)
        {
            assert(index >=0 && index < size); 
            pa[index] = element; 
        }
}; 

int main(void)
{
    array<Date> A1(5);
    array<int> A2(10); 
    
    for(size_t i = 0; i < 5; ++i)
        A2.set(i, i);  

    return (0); 
}