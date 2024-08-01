#include "operator.hpp"

	opt::opt() : n(0){
	}
	opt::opt(int n_) : n(n_) {
	}
	opt opt::operator+(const opt& other) const{
		opt result;
		result.n = n + other.n;
		return (result);
	}	
	opt opt::operator-(const opt& other) const{
		opt result;
		result.n = other.n - n;
		return (result);
	}

	opt opt::operator/(const opt& other) const{
		opt result;
		result.n = n / other.n;
		return (result);
	}

	opt opt::operator*(const opt& other) const{
		opt result;
		result.n = other.n * n;
		return (result);
	}	
	opt opt::operator%(const opt& other) const{
		opt result;
		result.n = other.n % n;
		return (result);
	}

	opt opt::operator<(const opt& other) const{
		opt result;
		result.n = n < other.n;
		return (result);
	}

	opt opt::operator>(const opt& other) const{
		opt result;
		result.n = n > other.n;
		return (result);
	}

	opt opt::operator<=(const opt& other) const{
		opt result;
		result.n = n <= other.n;
		return (result);
	}

	opt opt::operator>=(const opt& other) const{
		opt result;
		result.n = n >= other.n;
		return (result);
	}
	opt opt::operator==(const opt& other) const{
		opt result;
		result.n = n == other.n;
		return (result);
	}

	opt opt::operator!=(const opt& other) const{
		opt result;
		result.n = n != other.n;
		return (result);
	}

	opt opt::operator!() const{
		opt result;
		result.n = !n;
		return (result);
	}

	opt opt::operator|(const opt& other) const{
		opt result;
		result.n = n | other.n;
		return (result);
	}

	opt opt::operator&(const opt& other) const{
		opt result;
		result.n = n & other.n;
		return (result);
	}

	opt opt::operator^(const opt& other) const{
		opt result;
		result.n = n ^ other.n;
		return (result);
	}

	opt opt::operator~() const{
		opt result;
		result.n = ~n;
		return (result);
	}

	opt opt::operator<<(const opt& other) const{
		opt result;
		result.n = n << other.n;
		return (result);
	}

	opt opt::operator>>(const opt& other) const{
		opt result;
		result.n = n >> other.n;
		return (result);
	}

	opt opt::operator&&(const opt& other) const{
		opt result;
		result.n = n && other.n;
		return (result);
	}

	opt opt::operator||(const opt& other) const{
		opt result;
		result.n = n || other.n;
		return (result);
	}

	std::ostream& operator<<(std::ostream& os, const opt& other){
			os << other.n;
			return (os);	
		}

	opt opt::operator++(){
		n = n + 1;
		return *this;
	}

	opt opt::operator++(int){
		opt temp(n);
		n = n + 1;
		return (temp);
	}

	std::istream& operator>>(std::istream& is, opt& other){
		std::cout << "Enter a number=" << std::endl;
		is >> other.n;
		return (is);
	}
		