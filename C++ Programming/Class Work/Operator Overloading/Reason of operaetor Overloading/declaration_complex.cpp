#include <cstdio> 
#include <cstdlib> 

class Complex{
    private: 
        double re, im; 

    public: 
        Complex(); 
        Complex(double, double); 

        Complex add(const Complex&) const; 
        Complex sub(const Complex&) const; 
        Complex mul(const Complex&) const; 
        Complex div(const Complex&) const; 

}; 

Complex::Complex(){

}

Complex::Complex(double, double){

}

Complex Complex::add(const Complex&) const{

}

Complex Complex::sub(const Complex&) const{

}

Complex Complex::mul(const Complex&) const{

}

Complex Complex::div(const Complex&) const{
    
}
