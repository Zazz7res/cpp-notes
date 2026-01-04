#include <stdio.h>
void menu(void);
int for_choice(int, int);
int main(void) {
    printf("Please chose one of the following:\n");
    menu();
    printf("Enter the number of your choice:\n");

    int a = 0, b = 0;
    scanf("%d %d", &a, &b);
    for_choice(a, b);

    return 0;
}

void menu(void) {
    printf("1) copy files           2) move files\n");
    printf("3) remove files         4) quit\n");
}

int for_choice(int a, int b) {
    
    return 4;
}
