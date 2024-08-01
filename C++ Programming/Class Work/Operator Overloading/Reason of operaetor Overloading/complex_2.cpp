#include <cstdio> 
#include <cstdlib> 

class Complex{
    private: 
        double re, im; 

    public: 
        Complex() : re(0.0), im(0.0){

        }

        Complex(double _re, double _im) : re(_re), im(_im){

        }

        // CORRECT & PREFERRED & RECOMMENDED 
        Complex add(const Complex& second_number) const {
            Complex summation_object; 

            summation_object.re = this->re + second_number.re; 
            summation_object.im = this->im + second_number.im; 

            return (summation_object); 
        }

        void show(const char* msg){
            if(msg)
                puts(msg); 

            printf("(%.2lf)+i(%.2lf)\n", this->re, this->im); 
        }
}; 


int main(void){
    Complex c1(1.1, 2.2); 
    Complex c2(3.2, 4.1); 
 
    c1.show("Showing c1:"); 
    c2.show("Showing c2:"); 

    Complex sum; 

    sum = c1.add(c2); // Complex::add(&c1, c2); 
    sum.show("Showing summation of c1 and c2:"); 

    return EXIT_SUCCESS; 
}