#ifndef _COMPLEX_VECTOR_
#define _COMPLEX_VECTOR_
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iostream>

const int TEST_MAX = 10;
class complex{
	private:
		float real;
		float img;
	public:
		complex();
		complex(float real_, float img_);
		complex add(complex second_number);
		void show(const char* msg) const;
};
#endif

