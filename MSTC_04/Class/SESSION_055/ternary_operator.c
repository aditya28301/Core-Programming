/*'
@Goal: To demonstrate the syntax of ternary operator

we have define an integer m and its initialized to 5.

we have defined another integer n whose value will be input from the end
user.

And we have defined another result, which will sotre an output value to be printed.

if n is 0 or positive then the result will be set to the square of m.
else the result will be stored to the cube of m.

*/

#include <stdio.h>

int main(void)
{
    int n;
    int m = 5;
    int result = 0;
    printf("Enter the value of n:");
    scanf("%d", &n);

    result = (n > 5)?(!(n < 0)):((n >= 0));

    printf("Result = %d\n", result);
}