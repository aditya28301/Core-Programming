#include <cstdio>
#include <cstdlib>


class CPAint{
	private:
		int n;
	
	public:
		CPAint() : n(0){
		}

		CPAint(int _n) : n(_n){
		}

		CPAint operator+(const CPAint& other) const{
			CPAint  result;
			result.n = n + other.n;
		
			return (result);
		}

		CPAint operator-(const CPAint& other) const{
			CPAint result;

			result.n = other.n - n;

			return (result);
		}

		CPAint operator*(const CPAint& other) const{
			CPAint result;
			result.n = n * other.n;
	
			return (result);
		}

		CPAint operator/(const CPAint& other) const{
			CPAint result;
			result.n = n / other.n;

			return (result);
		}

		CPAint operator%(const CPAint& other) const{
			CPAint result;
			result.n = n % other.n;
	
			return (result);
		}

		void show(const char* msg) const{
			if(msg)
				puts(msg);
			printf("Result = %d\n", n);
		}

};

int main(void){
	CPAint c1(10);
	CPAint c2(20);
	CPAint result;
	
	result = c1 + c2;
	result.show("Addition of n1 + n2");
	
	result = c2 - c1;
	result.show("Subtraction of n2 - n1");

	result = c1 * c2;
	result.show("Multiplication of n1 * n2");

	result  = c1 / c2;
	result.show("Division of n1 / n2");

	result = c1 % c2;
	result.show("Modolus of  n1 % n2");

	puts("Programmer terminated succesfully");
	return 0;
}