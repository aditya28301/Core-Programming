#include <iostream> 

const int ARR_SIZE = 4; 

class B{
    private: 
        int n1, n2; 
    public:
        B() : n1(100), n2(200){

        }

        void show(const char* msg) const {
            if(msg)
                std::cout << "msg:" << msg << std::endl; 
            std::cout << "B::show():n1:" << n1 << " n2:" << n2 << std::endl; 
        }

        void set(int _n1, int _n2){
            n1 = _n1; 
            n2 = _n2; 
        }
}; 

class D1 : public B{
    private: 
        double d1, d2; 
    public: 
        D1() : d1(1.1), d2(2.2){

        }

        void show(const char* msg) const {
            if(msg)
                std::cout << "msg:" << msg << std::endl; 
            std::cout << "D1::show():d1:" << d1 << " d2:" << d2 << std::endl; 
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
                a[i] = (i+1) * 1000; 
            }
        }

        void show(const char* msg) const {
            if(msg)
                std::cout << "msg:" << msg << std::endl; 
            for(std::size_t i = 0; i != ARR_SIZE; ++i){
                std::cout << "a[" << i << "]:" << a[i] << std::endl; 
            }
        }
}; 

int main(void){
    D2 objD2; 

    objD2.show("Showing D2 specific part in objD2:"); // 1000, 2000, 3000, 4000

    (dynamic_cast<D1*>(&objD2))->show("Showing embedded D1 object in D2:"); // 1.1 2.2 
    (dynamic_cast<B*>(&objD2))->show("Showing embedded B object in D1 embedded in D2:"); // 100 200 
    
    B objB; 
    D1 objD1; 

    objB.show("BEFORE:Showing standalone object of B viz. objB:"); // 100, 200 
    objD1.show("BEFORE:Showing standalone object of D1 viz. objD1:"); // 1.1 2.2
    (dynamic_cast<B*>(&objD1))->show("BEFORE:Showing embedded B in objD1"); // 100, 200

    // d1, d2 members of embedded object D1 in D2 are reset to 100.1, 200.1 from 1.1, 2.2 
    (dynamic_cast<D1*>(&objD2))->set(100.1, 200.1); 
    // n1, n2 members of embedded object B in D1 which in turn is an embedded object in D2 
    // are reset to -100, -200 from 100, 200
    (dynamic_cast<B*>(&objD2))->set(-100, -200); 

    (dynamic_cast<D1*>(&objD2))->show("AFTER resetting members of object D1 embedded in D2"); // 100.1 200.1
    (dynamic_cast<B*>(&objD2))->show("AFTER resetting members of object B embedded in D1 which is embedded in D2:"); // -100 -200

    objB = objD2; 
    objD1 = objD2; 

    objB.show("AFTER:Showing standalone object of B viz. objB:"); // -100, -200 
    objD1.show("AFTER:Showing standalone object of D1 viz. objD1:"); // 100.1 200.2
    (dynamic_cast<B*>(&objD1))->show("AFTER:Showing embedded B in objD1"); //-100, -200

    return EXIT_SUCCESS;
}