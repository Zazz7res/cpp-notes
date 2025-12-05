/*  review4.c  --  使用代码测试条件
 * 4．用代码表示以下测试条件：　　
 * a．scanf()成功读入一个整数　　
 * b．x 不等于5　　
 * c．x 大于或等于20 */ 

#include <stdio.h>
int main(void) {
    int x = 1;
    
    printf("请输入一个整数数字：\n");
    while (scanf("%d", &x)) {
        printf("scanf()成功读入一个整数\n");
        break;
    }

    if (x != 5) {
        printf("x不等于5\n");
    }

    if (x >= 20) {
        printf("x 大于或等于20");
    }
    return 0;
}
