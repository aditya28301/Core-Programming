#include <iostream> 

const int ARR_SIZE = 4; 

class B{
    private: 
        int n1, n2; 
    public:
        B() : n1(100), n2(200){

        }

        void show() const {
            std::cout << "n1:" << n1 << " n2:" << n2 << std::endl; 
        }
}; 

class D1 : public B{
    private: 
        double d1, d2; 
    public: 
        D1() : d1(1.1), d2(2.2){

        }

        void show() const {
            std::cout << "d1:" << d1 << " d2:" << d2 << std::endl; 
        }

        void set(double _d1, double _d2) {
            d1 = _d1; 
            d2 = _d2; 
        }
}; 

class D2 : public D1 {
    private: 
        int a[ARR_SIZE]; 
    public: 
        D2(){
            for(std::size_t i = 0; i != ARR_SIZE; ++i){
                a[i] = (i+1) * 100; 
            }
        }

        void show() const {
            for(std::size_t i = 0; i != ARR_SIZE; ++i){
                std::cout << "a[" << i << "]:" << a[i] << std::endl; 
            }
        }
}; 

int main(void){
    D2 objD2; 
    D1* pD1 = 0; 
    B* pB = 0; 

    objD2.show(); // D2::show() -> int a[4] will be shown 
    (*dynamic_cast<D1*>(&objD2)).show(); // D1::show() -> d1 and d2 will be shown 
    (*dynamic_cast<B*>(&objD2)).show();  // B::show() -> n1 and n2 will be shown 

    // int a[4] is a member of object D2 
    // d1 and d2 are members of object D1 which is embedded (part of) object objD2 
    // n1 and n2 are members of object B which is embedded (part of) object objD2; 

    pB = reinterpret_cast<B*>(&objD2); 
    pD1 = reinterpret_cast<D1*>(&objD2);

    std::cout << "pB:" << pB << std::endl; 
    std::cout << "pD1:" << pD1 << std::endl; 
 

    return EXIT_SUCCESS; 
}