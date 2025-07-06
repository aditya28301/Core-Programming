#include <iostream> 

class B1 {
    private: 
        int n1, n2; 
}; 

class B2{
    private: 
        double d1, d2; 
}; 

class D : public B1, public B2{
    private: 
        int a[4];
}; 

int main(void){
    D objD; 

    D* pD = &objD; 
    B1* pB1 = dynamic_cast<B1*>(&objD); 
    B2* pB2 = dynamic_cast<B2*>(&objD); 

    std::cout << "pD:" << pD << std::endl; 
    std::cout << "pB1:" << pB1 << std::endl; 
    std::cout << "pB2:" << pB2 << std::endl; 

    return EXIT_SUCCESS; 
}