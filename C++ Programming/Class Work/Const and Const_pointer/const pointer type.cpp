#include <cstdio>

int g_num = 200;
const int gc_num = 300;

int main(void){

// pointer
    int l_num = 10;
    const int lc_num = 100;

    int* ptr = &l_num;

//const local int to const int
    const int* pp;
    pp = &lc_num;

// global variable to pointer
    pp = &gc_num;    pp = &l_num;
    pp = &g_num;

    // *pp = 100 ERROR

    return 0;
}
