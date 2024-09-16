#include <stdio.h>

#define ARRAY_SIZE 10
#define ESC_BUTTON 27

void Get_Details(void);
void Display_data(int, char[], float);

struct Employee
{
    unsigned int Emp_id;
    char Name[ARRAY_SIZE];
    float salary;
};

struct Employee e_input;

int main(void)
{
    int id;
    char Name[ARRAY_SIZE];
    float salary;

    Get_Details();

    id = e_input.Emp_id;
    int i;
    for(i = 0; i < ARRAY_SIZE; ++i)
    {
        Name[i] = e_input.Name[i];
    }
   
    salary = e_input.salary;

    Display_data(id, Name, salary);

    return (0);
}

void Get_Details(void)
{
    int i;
    char Store_char;
    int isCheck;
    printf("Enter a Employee id\n");
    scanf("%d", &e_input.Emp_id);

    printf("Enter Name of your employee\n");
    puts("Please Press Enter button once you typed each character");
    for(i = 0; i < ARRAY_SIZE; ++i)
    {
            scanf(" %c", &Store_char);
            e_input.Name[i] = Store_char;
    }

    printf("Enter salary of employee\n");
    scanf("%f", &e_input.salary);
}

void Display_data(int id, char Name[], float salary)
{
    int i= 0;
    printf("\n\nEmployee Name is ");
    while(i < ARRAY_SIZE)
    {  
        printf("%c", Name[i]); 
         i = i+1;
    }
    printf("\nEmployee id is = %d\n", id);
    printf("Employee salary is =%.3f\n", salary);
}
