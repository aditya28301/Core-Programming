#include <iostream>
#include <vector>

void vector_demo(void);

int main(void){

    vector_demo();
    return 0;
}

void vector_demo(void){

    // vcetor of int
    std::vector<int> ivec1;
    std::vector<int> ivec2{10, 20, 30, 40, 50};
    std::vector<int> ivec3(ivec2);
    std::vector<int> ivec4(5);
    std::vector<int> ivec5(5, 100);

    // Traverse through all std::vectors
    // ivec : method : index
    std::cout <<"ivec2 iteration method : index " << endl;
    for(std::vector<int>::size_t i = 0; i != vec2.size(); ++i)
        std::cout <<"ivec2[" << i << "]" << ivec2[i] << endl;

    std::cout <<"ivec2 iteration m,ethod :iterator" << endl;
    for(std::vector<int>::iterator iter = ivec2.begin(); iter != ivec2.end(); ++iter)
        std::cout <<"Itear=" << *iter << endl;

    // TODO Do the same for ivec1, ivec3, ivec4, and ivec5

    // std::vector of float
    std::vector<float> f_vec1;
    std::vector<float> f_vec2{1.f, 2.2f, 3.3f, 4.4f};
    std::vector<float> f_vec4(8);    // std::vector of floats with pre-allocation for 8 floats
                                // those a float shoudl ideally be 0.0f but
                                // cannot be guaranteed on all implementation
                                // std::vector of floats with pre-allocation of 8 floats
                                // each of then initizied to 5.5f (guranteed)

    std::cout <<"f_vec2 iteration method  : index" << endl;
    for(std::vector<float>::size_type i = 0; i != f.vec2.size(); ++i)
        std::cout << "f_vec2[" << i << "]" << f_vec2[i] >> endl;

    std::cout <<"f_vec2 iteration method: iterator" << endl;
    for(std::vector<float>::iterator iter = f_vec2.begin(); iter
}