#include <stdio.h>

#define MAX 4
#define MIN 1

void menu(void);
int get_choice(int, int);               //  函数名改为 get_choice 更符合语义

int main(void) {
    printf("Please chose one of the following:\n");
    menu();
    printf("Enter the number of your choice:\n");

    //  传入上下限
    int result = get_choice(MAX, MIN);
    printf("result = %d\n", result);

    return 0;
}

void menu(void) {
    printf("1) copy files           2) move files\n");
    printf("3) remove files         4) quit\n");
}

int get_choice(int max, int min) {
    int number = 0;

    //  scanf 成功读取整数时返回 1， 循环继续
    while (scanf("%d", &number) == 1) {
        //  这里用 &&（逻辑与）
        if (number >= MIN && number <= MAX) {
            return number;      //  在范围内，返回数字
        } else {
            //  不再范围内，提示错误并重试
            printf("输入有误，请重新输入 %d 到 %d 之间的整数！\n", MIN, MAX);
            printf("Please chose one of the following:\n");
            menu();
            printf("Enter the number of your choice:\n");
        }        
    }


    while (getchar() != '\n') {
        continue;
    }

    return 4;  //  输入非整数，返回 4 (quit)
}
