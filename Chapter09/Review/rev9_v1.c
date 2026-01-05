#include <stdio.h>
#define MAX 4
#define MIN 1
void menu(void);
int for_choice(int, int);
int main(void) {
    printf("Please chose one of the following:\n");
    menu();
    printf("Enter the number of your choice:\n");
    int result = for_choice(MAX, MIN);
    printf("result = %d\n", result);
    return 0;
}

void menu(void) {
    printf("1) copy files           2) move files\n");
    printf("3) remove files         4) quit\n");
}

int for_choice(int a, int b) {
    int number = 0;
    while (scanf("%d", &number)) {
        if (number >= MIN || number <= MAX) {
            return number;
        } else {
            printf("输入有误，请输入一个整数！\n");
            printf("Please chose one of the following:\n");
            menu();
            printf("Enter the number of your choice:\n");
        }
    }
        
    return 4;
}
