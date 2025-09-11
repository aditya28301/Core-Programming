#include <stdio.h>

void use_struct_date(void);
void use_struct_student(void);

struct Date
{
    int day;
    int month;
    int year;
};

struct Student
{
    char student_name[32];
    char student_city[32];
    char student_email[64];
    int student_roll_number[64];
    float student_marks_in_percentage;
    unsigned long long int student_contact_number;
    struct Date student_birth_date;
};

struct Date my_date_1;

void use_struct_date(void)
{
    
    struct Date my_date_2;
    struct Date my_date_3;
    struct Date my_date_4;
    struct Date my_date_5;

    my_date_1.day = 1;
    my_date_1.month = 1;
    my_date_1.year = 1970;

}
void use_struct_student(void)
{
    struct Student st_1;
    struct Student st_2;
    struct Student st_3;
    struct Student st_4;
    struct Student st_5;
}

int main(void)
{

    use_struct_date();
    printf("day = %d\n", my_date_1.day);
    printf("Month = %d\n", my_date_1.month);
    printf("year = %d\n", my_date_1.year);
}

/*
Practice

#inlcude <stdio.h>
struct Date 
{
    int day;
    int month;
    int year;
};

struct Student
{
    char student_name[32];
    char student_city[32];
    char student_email[64];
    int student_roll_number;
    flaot student_marks_ini_percentage;
    unsigned long long int student_contact_number;
    struct Date student_birth_date;
};

void use_struct_date(void);
void use_struct_date(void);
------------------------------------------------------------------------------------
2.
#include <stdio.h>

struct Date
{   
    int day;
    int month;
    int year;
};

strcut Student
{
    char student_name[32];
    char student_city[32];
    int student_roll_number;
    float student_marks_int_percentage;
    unsgined long long int student_contact_number;
    struct Date student_birt_date;
};

void use_struct_date(void)
{
    struct Date my_date_1;
    struct Date my_date_2;
    struct Date my_date_3;
    struct Date my_date_4;
    struct Date my_date_5;
}

---------------------------------------------------------------------

void use_struct_date(void)
{
    struct Date my_data_1;
    struct Date my_date_2;
    struct Date my_date_3;
    struct Date my_date_4;
    struct Date my_date_5;
}

void use_struct_date(void)
{
    

}
*/