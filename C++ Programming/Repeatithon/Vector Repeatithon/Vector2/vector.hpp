#ifndef _VECTOR_HPP
#define _VECTOR_HPP
#include <cstdio>
#include <cstdlib>	

const int SUCCESS = 1;
const int VECTOR_INDEX_ERROR = -1;
//const int EXIT_SUCCESS = 0;

class vector{
	private:
		size_t* p_array;
		size_t N;
		
	public:
		vector();
		~vector();
		void PushBack(size_t data);
		void ShowVector(void) const;
		int get(size_t index, size_t* g_data) const;
		int set(size_t index, size_t data);
		int size(void);
};

#endif