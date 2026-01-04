//  菜还不认真
#include <stdio.h>

//  函数声明（原型）
int add(int, int);

int main(void) {
    int a = 1, b = 3;

    //  函数调用
    int total = add(a, b);

    printf("结果是 total = %d\n", total);

    return 0;
}

//  函数定义
int add(int a, int b) {
    int result = a + b;
    return result;
}
