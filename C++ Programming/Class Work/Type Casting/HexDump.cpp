#include <cstdio>
#include <cstdlib>

void hex_dump(void* add, unsigned long long int N, char* msg);

int main(void){
    int a = 0x0a0b0c0d;
    unsigned long long int b = 3423423423423;
    struct c{
        int aa;
        char bb;
        float cc;
    } inc = {100, 'A', 35.14};

    printf("original of a = %hhx\n", a);
    printf("original of b = %llx\n", b);
    printf("original of c = %llx\n", (unsigned long long int)&inc);

    printf("\n");
    hex_dump(&a, sizeof(a), "Hex_dump of a");
    hex_dump(&b, sizeof(b), "\nHex_dump of b");
    hex_dump(&inc, sizeof(inc), "\nHex_dump of c");

    return EXIT_SUCCESS;
}

void hex_dump(void* add, unsigned long long int N, char* msg){
    if(msg)
        puts(msg);
        
    for(size_t i = 0; i < N; ++i){
        printf("hex_dump of BYTE(%llx) = %hhx\n", i, *(unsigned char*)((unsigned char*)add + i));
    }
}