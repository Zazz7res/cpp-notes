/*  review3.c  --  测试条件  */ 
#include <stdio.h>
int main(void) {
    double x = 6;

    while (x > 5) {
        printf("x大于5\n");
        break;
    }

    while (scanf("%lf\n", &x)) {
        printf("读取成功！\n");
        break;
    }
    printf("scanf()读取失败\n");

    x = 5;
    while (x == 5) {
        printf("x = 5\n");
        break;
    }
    
    return 0;
}
