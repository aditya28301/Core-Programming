#include <stdio.h>  /*For declearation of printf() and scanf() */
#include <math.h>   /*For declaration of sqrt() */

int main(void){

    double x1;  /* x-coordinate of point 1*/
    double y1;  /* y-cooridnate of point 2*/
    double x2;  /*x-coordinate of point 1*/
    double y2;   /*y-coordinate of point 2*/
    double d;   /* Distance between of points */

    printf("Enter the x-coordinate of point 1:");
    scanf("%lf", &x1);

    printf("Enter y-coordinate of point 1:");
    scanf("%lf", &y1);

    printf("Enter x-coordinate of point 2:");
    scanf("%lf", &x2);

    printf("Enter y-coordinate of point 2:");
    scanf("%lf", &y2);

    /*  Simplified version */
    double tmp1 = x2 - x1;
    double tmp2 = y2 - y1;
    double tmp3 = tmp1*tmp1 + tmp2*tmp2;
    d = sqrt(tmp3);

    /* Proper version*/
    d = sqrt(pow(x2-x1, 2.0) + pow(y2-y1, 2.0));
    printf("PROPER VERSION: DISTANCE=%.3lf\n", d);

    return (0);
}