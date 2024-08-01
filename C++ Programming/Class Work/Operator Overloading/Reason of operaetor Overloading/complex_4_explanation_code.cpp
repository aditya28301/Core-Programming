#include <cstdio> 
#include <cstdlib> 

class Complex{
    private: 
        double re, im; 

    public: 
        Complex() : re(0.0), im(0.0) {

        }

        Complex(double _re, double _im) : re(_re), im(_im) {

        }

        void show(const char* msg) const {
            if(msg)
                puts(msg); 

            printf("(%.2lf) + i(%.2lf)\n", re, im); 
        }

        Complex& add(const Complex& second_number) const {
            static Complex summation_object; 

            summation_object.re = this->re + second_number.re; 
            summation_object.im = this->im + second_number.im; 

            return summation_object; 
        }
}; 

int main(void){
    Complex c1(1.1, 2.2); 
    Complex c2(3.3, 4.4); 
    Complex c3(5.5, 6.6); 
    Complex c4(7.7, 8.8); 

    c1.show("c1:"); 
    c2.show("c2:"); 
    c3.show("c3:");
    c4.show("c4:");  

    Complex& refSum1 = c1.add(c2); 
    refSum1.show("Showing refSum1:additiono of c1 and c2"); 
    
    Complex& refSum2 = c3.add(c4); 
    refSum2.show("Showing refSum2:addition of c3 and c4"); 

    refSum1.show("Showing refSum1:addition of ?? (SURPRISE! SURPRISE!!)"); 

    printf("&refSum1 = %llu, &refSum2 = %llu\n",
            (unsigned long long)&refSum1, 
            (unsigned long long)&refSum2 
        ); 

    return 0; 
}