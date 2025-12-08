#include <stdio.h>
#define YEAR_TO_DAY 365

int main(void) {
    int age, change_to_day;
    printf("请输入你的年龄：\n");
    scanf("%d", &age);

    change_to_day = age * YEAR_TO_DAY;

    printf("你的天数是：%d\n", change_to_day);
    return 0;
}
