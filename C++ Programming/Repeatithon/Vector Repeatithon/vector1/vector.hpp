#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <cstdio>
#include <cstdlib>

const int SUCCESS  = 1;
const int VECTOR_INDEX_ERROR = -1;
class vector{
    private:
        size_t* p_array;
        size_t N;

    public:
        vector();
        ~vector();
        void Push_Back(size_t new_data);
        void Show_Vector(const char* msg) const;
        int get(size_t index, size_t* p_data) const;
        void set(size_t index, size_t new_data);
        int size(void) const;
};

#endif  //_VECTOR_HPP 