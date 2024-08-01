#include "operator.hpp"

opt::opt() : arr(0), n(0){}
opt::opt(size_t size) : n(size), arr(new size_t[size]){}

		std::ostream& operator<<(std::ostream& os, const opt& other){
			os << other.n;
			return (os);
		}

		std::istream& operator>>(std::istream& is, opt& other){
			std::cout <<"Enter a number"<<std::endl;
			is>>other.n;
			return (is);
		}

		size_t& opt::operator[](const size_t index) const{
			return arr[index];
		}
		void opt2::set(size_t (*ptr)(size_t, size_t)){
			ptr_function = ptr;
		}
		size_t opt2:: operator()(size_t index1, size_t index2){
			return ptr_function(index1, index2);
		}

		opt::~opt(){
			delete[] arr;
		}