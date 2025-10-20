#define B "bobobo"
#define X 10
#include <stdio.h>

int main(void)
{
    int age, xp;
    char name;
    printf("Please enter your first name.");
    scanf("%s",&name);
    printf("All right, %c, what's your age?\n", name);
    scanf("%d", &age);
    xp = age + X;
    printf("That's a %s! You must be at least %d.\n", B, xp);



    return 0;

}
