#pragma once 

#include <cstdlib>
#include <cstdio>
#include <iostream>
class opt{
	private:
		size_t* arr;
		size_t n;
		
	public:

		opt();
		opt(size_t n);
		~opt();
		friend std::ostream& operator<<(std::ostream& os, const opt& other);
		friend std::istream& operator>>(std::istream& is, opt& other);
		size_t& operator[](const size_t index) const;
		
		
};

class opt2{
	private:
		size_t (*ptr_function)(size_t, size_t);
	public:
		opt2() : ptr_function(0){}
		void set(size_t (*ptr)(size_t, size_t));
		size_t operator()(size_t num1, size_t num2);
};	

