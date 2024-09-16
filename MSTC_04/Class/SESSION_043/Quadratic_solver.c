#include <stdio.h>  /*   For decleration of printf(), puts(), scanf()*/
#include <math.h>   /*  For decleration of exit()   */
#include <stdlib.h> /*  For decleration of sqrt()   */

int main(void)
{
    double a;   /*  For storing Co-efficient of x^2 */
    double b;   /*  For storing Co-effiecient of x */
    double c;   /*   For storing constant */
    double root_1;  /*  For storing the value of root 2 */
    double root_2;  /*  For storing the value of root 2 */
    double delta;

    printf("Enter the CF of x^2:");
    scanf("%lf", &a);

    if(a == 0.0)
    {
        puts("CF of x^2 cannot be zero in quadratic equaiton");
        exit(-1);
    }
    printf("Enter the CF of x:");
    scanf("%lf", &b);

    printf("Enter the constant:");
    scanf("%lf", &c);

    if((b*b - 4*a*c) <= 0.0)
    {
        puts("This quadratic equa tion does not have real roots");
        exit(-1);
    }

    delta = sqrt(b*b-4*a*c);
    root_1 = (-b + delta) / (2*a);
    root_2 = (-b - delta)/(2*a);

    printf("root_1:%.3lf, root_2:%.3lf\n", root_1, root_2);
    return (0);

}