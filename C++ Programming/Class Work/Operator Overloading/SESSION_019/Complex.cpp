/*
	@author: 	Aditya Darekar
	@date:		27 June 2024
	@goal:		Demonstrate opeartor overloading non-modular implementation (client-server are present in the same source file)	
*/

#include <cstdlib>
#include <cstdio>
	
//SERVER SIDE
class Complex{
	private:
		double re, im;
		
	public:
		Complex() : re(0.0), im(0.0){
		}
		
		Complex(double _re, double _im) : re(_re), im(_im){
		}
		
		void show(const char* msg) const{
			if(msg)
				puts(msg);
			printf("(%3.lf) + i(%3.lf)\n", re, im);
		}

		// Complex add(const Complex& other) const;
		Complex operator+(const Complex& other) const{
			Complex result;

			result.re = re + other.re;
			result.im = im + other.im;
			
			return (result);
		}

		Complex operator-(const Complex& other) const{
			Complex result;

			result.re = re - other.re;
			result.im = im - other.im;
			
			return (result);
		}
};

//CLIENT SIDE
int main(void){
	Complex c1(1.1, 2.2);
	Complex c2(3.3, 4.4);

	Complex summation = c2 + c1;
	Complex subtraction = c2 - c1;

	c1.show("c1");
	c2.show("c2");
	summation.show("summation:");
	subtraction.show("subtraction:");

	return 0;
}