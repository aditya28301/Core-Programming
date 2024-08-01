#ifndef _VECTOR_HPP
#define _VECTOR_HPP
#include <cstdlib>
#include <cstdio>

const int SUCCESS = 1;
const int VECTOR_INDEX_ERROR = -1;

class vector{
	private:
		size_t* p_array;
		size_t N;
		
	public:
		vector();
		~vector();
		void PushBack(size_t new_data);
		void showVector(void) const;
		void get(size_t index, size_t* g_data) const;
		void set(size_t index, size_t new_data);
		size_t size(void);
};
#endif