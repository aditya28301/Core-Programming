#include "operator.hpp"

opt::opt() : arr(0), n(0) {}
opt::opt(size_t size) : n(size), arr(new size_t[size]){}		
size_t& opt::operator[](const size_t& index){
	return arr[index];
}
std::ostream& operator<<(std::ostream& os, const opt& other){
	os << other.n;
	return (os);
}
std::istream& operator>>(std::istream& is, opt& other){
	is >> other.n;
	return (is);
}

//Class 2

void opt2::set(size_t (*ptr)(size_t, size_t)){
	ptr_function = ptr;
}
size_t opt2::operator()(size_t num1, size_t num2){
	return ptr_function(num1, num2);
}
