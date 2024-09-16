#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    double x1, y1;  /* For storing x-y co-oridnate of point A   */
    double x2, y2;  /* For storing -y co-ordinate of point  B   */
    double x3, y3;  /* For storing x-y co-ordinate of point C   */

    double a;   /* For storing length of side BC    */
    double b;   /* For storing length of side CA    */
    double c;   /* For storing lenth of sdie AB     */

    double A;   /* For storing measure of angle A in radians    */
    double B;   /* For storing measure of angle B in readians   */
    double C;   /* For storig measure of angle  C in radians    */

    printf("Enter x co-oridnate of vertex A:");
    scanf("%lf", &x1);

    printf("Enter y co-ordiante of vertex A:");
    scanf("%lf", &y1);

    printf("Enter x co-ordinate of vertex B:");
    scanf("%lf", &x2);

    printf("Enter y co-ordiante of vertex B:");
    scanf("%lf", &y2);

    printf("Enter x co-ordinate of vertex C:");
    scanf("%lf", &x3);

    printf("Enter x co-orindate of vertex C:");
    scanf("%lf", &y3);

    /* a = lenght of (BC)   */
    a = sqrt(pow(x2-x3, 2) + pow(y2-y3,2));

    /* b = length of (CA)   */
    b = sqrt(pow(x3-x1, 2) + pow(y3-y1, 2));

    /* c = lenght of (AB)   */
    c = sqrt(pow(x3-x1, 2) + pow(y1-y2,2));

    if((a + b) <= c ||(b + c) <= a || (c + a) <=b)
    {
        puts("Sum of any two side of triangle is greater than its third side");
        puts("This condition is not satisfied");
        puts("Therfore, A, B, and C are collinear point that cant form a triangle");
        puts("exiting...");
        exit(-1);
    }

    A = acos((b*b + c*c - a*a)/(2*b*c));
    B = acos((c*c + a*a - b*b)/(2*c*a));
    C = acos((a*a + b*b  - c*c)/(2*a*b));
    printf("VertexA=(%.3lf, %.3lf)\n", x1, y1);
    printf("Vertexb+(%.3lf, %.3lf)\n", x2, y2);
    printf("VertexC=(%.3lf, %.3lf)\n", x3, y3);
    printf("l(AB)=%.3lf, l(BC)=%.3lf, l(AC)=%.3lf\n", c, a, b);
    printf("mA=%.3lf, mB=%.3lf, mC=%.3lf\n", A, B, C);

    return (0);

}