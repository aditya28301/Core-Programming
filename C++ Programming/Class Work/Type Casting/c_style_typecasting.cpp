#include <cstdio>
#include <cstdlib>

int main(void){
    size_t add = 0;
    *(unsigned char*)&add = 0xaa;
    printf("%llx\n", add);
    *(unsigned short*)((unsigned char*)&add + 1) = 0xbbcc;
    printf("%llx\n", add);
    *(unsigned int*)((unsigned char*)&add + 3) = 0xffffff;
    printf("%llx\n", add);
    return EXIT_SUCCESS;
}

/*
    [aa]

    [aa]    [bb]    []

    [aa]    [bb]    [cc]    []

    []      []      []      []      []

    []      []      []      []      []      []      []
    x       x+1     x+2     x+3     x+4     x+5     x+6
*/