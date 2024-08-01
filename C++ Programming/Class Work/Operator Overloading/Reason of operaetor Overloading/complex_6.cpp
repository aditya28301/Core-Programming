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
 
        // MEMORY MANAGEMENT WISE CORRECT 
        // THREAD SAFE 
        // BUT SYNTAXWISE AWKWARD 
        // Complex& sum = c1.add(c2); 

        // delete &sum;     // awkward! 

        // OBJECT CHAINING WILL LEAD TO MEMORY LEAK
        // c1.add(c2).add(c3).add(c4); 

        // SINGLE call -> CORRECT BUT AWKWARD HENCE NOT PREFERRED AND RECOMMENDED 
        // CHAING CALL -> MEMORY LEAK 

        Complex& add(const Complex& second_number) const {
            Complex* pSum = new Complex; 
            
            pSum->re = this->re + second_number.re; 
            pSum->im = this->im + second_number.im; 

            return (*pSum); 
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
    Complex c3(4.5, 6.7); 
 
    c1.show("Showing c1:"); 
    c2.show("Showing c2:"); 

    Complex& refSum = c1.add(c2); 

    Complex& refSum1 = refSum.add(c3); 

   

    delete &refSum; // correct but awkward 
    delete &refSum1; 

    // Complex& refSum1 = c1.add(c2).add(c3); // WILL LEAD TO CHAINING 

    return EXIT_SUCCESS; 
}
