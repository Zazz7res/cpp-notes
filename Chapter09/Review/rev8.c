/*  8．编写一个函数，返回3个整数参数中的最大值。 */
#include <stdio.h>

int max(int, int, int);

int main(void) {
    int a = 1, b = 6, c = 9;
    printf("现在有三个数：a = %d, b = %d, c = %d", a, b, c);
    printf("其中最大的数是:%d", max(a, b, c));
    return 0;
}

int max(int a, int b, int c) {
    if(a > b) {
        if (a > c) return a;
        else return c;
    } else {
        if (b > c) return b;
        else return c;
    }
}
