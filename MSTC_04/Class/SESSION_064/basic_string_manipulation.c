#include <stdio.h>
#define BLOCK 20

void print_details(struct personal_details);

struct professional_details
{
    char office_name[BLOCK];
    unsigned short Employee_id;
};
struct Address
{
    char office_address[BLOCK];
    char home_address[BLOCK];
};
struct personal_details
{
    char name[BLOCK];
    unsigned long long int ph_no;
    struct Address user_address;
    struct professional_details pro;
};

int main(void)
{
    struct personal_details user;

        memset(user.name, 0 , BLOCK);
        strncpy
        (
            user.name, 
            "aditya"    , 
            strlen("aditya")
        );

        memset(user.user_address.office_address, 0 , BLOCK);
        strncpy
        (
            user.user_address.office_address, 
            "Magarpatta", 
            strlen("Magarpatta")
        );

        memset(user.user_address.home_address, 0 , BLOCK);
        strncpy
        (
            user.user_address.home_address,
            "Baramati",
            strlen("Baramati")
        );

        user.ph_no = 7774896408;

        memset(user.pro.office_name, 0 , BLOCK);
        strncpy
        (
            user.pro.office_name,
            "Amdocs",
            strlen("Amdocs")
        );

        user.pro.Employee_id = 197747;

    print_details(user);

    return(0);
}

void print_details(struct personal_details d1)
{
    printf("name is %s\n", d1.name);
    printf("phone number %llu\n", d1.ph_no);
    printf("Home address %s\n", d1.user_address.home_address);
    printf("Office Name %s\n", d1.pro.office_name);
    printf("Employee id %hd \n", d1.pro.Employee_id);
    printf("Office location %s\n", d1.user_address.office_address);
};