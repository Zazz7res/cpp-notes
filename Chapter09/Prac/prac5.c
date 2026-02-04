/*
     * 5．编写并测试一个函数larger_of()，该函数把两个double类型变量的值替换为较大的值。
     * 如，larger_of(x, y)会把x和y中较大的值重新赋给两个变量。
*/

#include <stdio.h>

void larger_of(double *, double *);
int main(void) {
    double x = 0, y = 0;

    printf("请输入两个double 类型的字符: \n");
    scanf("%lf %lf", &x, &y);
    printf("x = %lf, y = %lf\n", x, y);
    larger_of(&x, &y);
    printf("x = %lf, y = %lf\n", x, y);

    return 0;
}

void larger_of(double *x, double *y) {
    if (*x > *y)
        *y = *x;
    else
        *x = *y;
}

