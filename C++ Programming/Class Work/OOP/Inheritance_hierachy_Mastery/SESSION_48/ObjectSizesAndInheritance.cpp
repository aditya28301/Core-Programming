#include <iostream> 

class B{
    private: 
        int n1, n2; 
}; 

class D1 : public B{
    private: 
        int d1, d2; 
}; 

class D2 : public D1{
    private: 
        int a[8]; 
}; 

class C{
    private: 
        int a[8]; 
}; 

int main(void){
    std::cout << "sizeof(C):" << sizeof(C) << std::endl; // 20 bytes 
    std::cout << "sizeof(B):" << sizeof(B) << std::endl; 
    std::cout << "sizeof(D1):" << sizeof(D1) << std::endl; 
    std::cout << "sizeof(D2):" << sizeof(D2) << std::endl;

    return 0;  
}