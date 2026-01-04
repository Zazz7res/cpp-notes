//  4．设计一个函数，返回两整数之和。
#include <stdio.h>

int add(int, int);  //  计算两数之和

int main(void) {

    int a = 1, b = 3;
    int total = add(a, b);
    printf("结果是total = add(a, b)");

}

int add(int a, int b) {
    int result = a + b;
    return result;

}

