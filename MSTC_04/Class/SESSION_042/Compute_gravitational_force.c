#include <stdio.h>  /*This line will be explained later*/

int main(void)
{
    double m1 = 0.0;    /*Variable to store the mass of object 1*/
    double m2 = 0.0;    /*Variable to store the mass of object 2 in kgs*/
    double G  = 6.67e-11;   /*Variable to sroe the distance between the objects in meters*/
    double r  = 0.0;    /*6.67 X 10^-11 The universal constant of gravitation*/
    double F  = 0.0;    /*The Variable store the actual result which is force*/

    printf("Enter mass of object 1 in Kgs:");
    scanf("%lf", &m1);

    printf("Enter mass of object 2 in Kgs:");
    scanf("%lf", &m2);

    printf("Enter distance between the objects in meters:");
    scanf("%lf", &r);

    F = (G * m1 * m2) / (r * r);    
    printf("The gravitational force between two objects = %.12lf Newtons \n", F);

    return (0);

}
