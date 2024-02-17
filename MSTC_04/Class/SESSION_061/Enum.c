#include <stdio.h>

enum Device
{
    MOUSE = 1,
    KEYBOARD,
    MONITOR,
    LAPTOP,
    SOUND
};

int main(void)
{
    enum Device check_choice = SOUND; 

    switch(check_choice)
    {
        case SOUND:
        printf("You Selected Sound= %d\n", check_choice);
        break;

        case LAPTOP:
        printf("Wrong choice selected\n");
        break;

        default:
        printf("You Entered another number which is not in scoped\n");
        break;

    }
    return (0);
}