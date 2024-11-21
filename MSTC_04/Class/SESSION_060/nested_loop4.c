#include <stdio.h>

int main(void)
{
    int i;
    int j;
    
    puts("Using while loop");
    i = 0;
    while(i < 5)
    {
        j = 0;
        while(j <= i)
        {
            printf("i =%d, j= %d\n", i , j);   
            j = j + 1;
        }
        i = i + 1;
    }

    puts("Using while loop");
    for(i =0 ;i < 5; ++i)
    {
        for(j = 0; j <= i; ++j)
        {
            printf("i = %d, j = %d\n", i, j);
        }
    }

    return (0);
}

/*

using while loop

i = 0, j = 0;
----------------------
i = 1, j = 0;
i = 1, j = 1;
------------------------
i = 2, j = 0;
i = 2, j = 1;
i = 2, j = 2;
-----------------------
i = 3, j = 0;
i = 3, j = 1;
i = 3, j = 2;
i = 3, j = 3;
-------------------------
i = 4, j = 0;
i = 4, j = 1;
i = 4, j = 2;
i = 4, j = 3;
i = 4, j = 4;
*/