#include <stdio.h>
#include <stdlib.h>

long long int* dArray(size_t_);
void iArray(long long int* arr, size_t size); 
void print(long long int* arr, size_t size);
void lSideMoveNegative(long long int*, size_t);

int main(void)
{
    // long long int* arr = NULL;
    long long int arr[100] = {-5165,2833,4480,4627,8671,-9446,-540,-2615,-9335,5607,6282,-1068,7377,-1043,-4126,-3917,-3487,-4708,5232,1127,618,-1231,-9805,-5921,9481,7442,1835,-1270,3694,3643,9639,5919,-2123,-11,-6451,3601,2215,-6535,385,-9472,2907,4452,-2994,-5193,-7286,-5053,908,729,399,-6946,-8704,-771,4338,-9521,-410,4639,-2479,-6734,2672,-564,6058,-2557,5016,7236,-7020,-9146,2503,-5404,6410,-5663,7957,8349,8835,2631,5291,-8645,-6650,7983,-423,6345,643,-5551,4816,836,8414,-3859,8411,-8457,4158,8615,9807,-9563,214,4660,-6810,3657,-6505,-4009,-8616,8079};
    size_t size = 100;

    
    // puts("Allocate array and get handle");
    // arr = dArray(size);

    puts("Insert element in array");

    // iArray(arr, size);
    puts("Move all Negative to the left side");
    lSideMoveNegative(arr, size);
    puts("Print the all element");
    print(arr, size);

    exit(0);
}
void swap(long long int* f, long long int* s)
{
    long long int temp;
    temp = *f;
    *f = *s;
    *s = temp;
}
void lSideMoveNegative(long long int* arr, size_t size)
{
    size_t t_Negative;
    size_t chk_Negative;

    t_Negative = 0;
    chk_Negative = 0;
    while(chk_Negative < size)
    {
        if(arr[chk_Negative] < 0)
        {
            swap(&arr[chk_Negative], &arr[t_Negative]);
            t_Negative = t_Negative + 1;
            chk_Negative = chk_Negative + 1;
        }
        else    
        {
            chk_Negative = chk_Negative + 1;
        }
    }
}
void print(long long int* arr, size_t size)
{
    for(size_t i = 0; i < size; ++i)
        printf("%lld\n", *(arr + i));
}
void iArray(long long int* arr, size_t size)
{
    for(size_t i = 0; i < size; ++i)
        *(arr + i) = (rand() % 99);
}
long long int* dArray(size_t size)
{
    long long int* ptr = NULL;
    ptr = (long long int*)malloc(size * sizeof(long long int));
    if(ptr == NULL)
    {
        puts("Error in allocating the memory");
        exit(EXIT_FAILURE);
    }
    return (ptr);
}