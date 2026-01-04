
//  菜还不认真
#include <stdio.h>

//  函数声明（原型）
double add(double, double);

int main(void) {
    double a = 1, b = 3;

    //  函数调用
    double total = add(a, b);

    printf("结果是 total = %lf\n", total);

    return 0;
}

//  函数定义
double add(double a, double b) {
    double result = a + b;
    return result;
}
