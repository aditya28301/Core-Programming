#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10  /* Symbolic Constant */

void Display_output(void);

int main(void)
{

    Display_output(LENGTH);    

    return (0);
}

void Display_output(int size)
{ i;
    int First_loop , Second_loop;
    for(int First_Loop = 0 ; First_loop < size ; ++First_loop)  
    {
        for(int Second_Loop = 0; Second_Loop < size; ++Second_Loop)    
        {
            printf("First Loop = %d, Second Loop = %d\n", First_loop, Second_loop);
        }
    }
}

