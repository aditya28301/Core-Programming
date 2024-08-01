#ifndef _OPT_HPP_
#define _OPT_HPP_

#include <cstdio>
#include <cstdlib>
#include <iostream>

class opt{
	private:
		int n;
	
	public:
		opt();
		opt(int n);
		
		opt operator+(const opt& other) const;
		opt operator-(const opt& other) const;
		opt operator/(const opt& other) const;
		opt operator*(const opt& other) const;
		opt operator%(const opt& other) const;
		opt operator<(const opt& other) const;
		opt operator>(const opt& other) const;
		opt operator<=(const opt& other) const;
		opt operator>=(const opt& other) const;
		opt operator==(const opt& other) const;
		opt operator!=(const opt& other) const;
		opt operator!() const;
		opt operator|(const opt& other) const;
		opt operator&(const opt& other) const;
		opt operator^(const opt& other) const;
		opt operator~() const;
		opt operator<<(const opt& other) const;
		opt operator>>(const opt& other) const;
		opt operator&&(const opt& other) const;
		opt operator||(const opt& other) const;
		opt operator++();
		opt operator++(int);
		friend std::ostream& operator<<(std::ostream& os, const opt& other);
		friend std::istream& operator>>(std::istream& is, opt& other);
		void show(const char* msg) const{
			if(msg) 
				puts(msg); 
			printf("result = %d\n", n);	
		}
};

#endif