#include <iostream> 
#include <utility>
#include <cstdlib> 

int& test_function_1(void); 
int&& test_function_2(void);

void test(void); 

int main(void)
{
    int n = 10, m = 20; 

    int& ref1 = n;      // ok 
    //int& ref2 = n * 10; // error 
    const int& ref3 = n * 10; // ok 

    //int&& ref4 = m;     // error 
    int&& ref5 = m*10;  // ok 
    int&& ref6 = 10 * 200;  // ok 

    std::cout << "ref5:" << ref5 << std::endl 
                << "ref6:" << ref6 << std::endl; 

    test(); 

    return (0); 
}

int& test_function_1(void)
{
    int* p = new int(100); 

    return *p; 
}

int&& test_function_2(void)
{
    return (10); 
}

void test(void)
{
    int&& rr1 = 100; 
    // int&& rr2 = rr1; // error
    int&& rr2 = std::move(rr1); 
    std::cout << "rr1:" << rr1 << std::endl; 
    std::cout << "rr2:" << rr2 << std::endl; 
}

// T&& 
// T&& 