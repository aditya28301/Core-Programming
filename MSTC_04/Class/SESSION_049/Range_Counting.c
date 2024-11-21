/*
@Goal:
Accept two integers from the end user, say, a and b
a must be a less than b. Add validations check for this condition.

Ask end user whether he/she wants to
1)INLCUDE both a and b while counting?
2)EXCLUDE both a and b while counting?
3)INCLUDE both a EXCLUDE b while counting?
4)EXCLUDE a and INCLUDE b while counting?

Depending on the end users choice output to the end user
the integers between a and b
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a;      /* for storing value of the first integers of the range*/
    int b;      /* for storing value of the second integers of the range */
    int choice; /* for storing choice of the end user regarding the inclusion/exclusion of the end points of the range */
    int number_of_integers; /* for storing number of integers between a and b as per end users choice */
    
    printf("Enter the first integre of the range:");
    scanf("%d", &a);

    printf("Enter the secind integer og ther anfe (greater than the first integer of the range):");
    scanf("%d", &b);

    if(a >=b )
    {
        puts("ERROR:The second integer of the ranfe must be range must be greater than the first. Existing...");
        exit(-1);
    }

    puts("Enter your choice regarinf the inclusion/exclsion of end points of the range:");
    puts("Enter 1 if you want to include both end points of the range:");
    puts("Enter 2 if you want to exclude both the end pointd of the range");
    puts("Enter 3 if you want to include the first and exclude the secind end points of the range.");
    puts("Enter 4 if you want to exclude the first and inckude the second end points of the range.");
    scanf("%d", &choice);

    if(choice == 1)
        number_of_integers = b - a + 1;
    else if(choice  == 2)
        number_of_integers = b - a - 1;
    else if(choice == 3 || choice ==4)
        number_of_integers = b -a;
    else
    {
        puts("ERROR:Invalid value for choice. The choice value must be between 1 to 4");
        exit(-1);
    }

    printf("Number of integer between %d and %d as per your inclusion/exclusion choice is %d\n",a, b, number_of_integers);

    return (0);
}