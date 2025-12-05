/*  简单测试一下  */ 
#include <stdio.h>

int main(void) {
    int quack = 2;
    printf("int quack = %d", quack);
    quack += 5;
    printf("quack += %d", quack);
    quack *= 10;
    printf("quack *= %d", quack);
    quack -= 6;
    printf("quack -= %d", quack);
    quack /= 8;
    printf("quack /= %d", quack);
    quack %= 3;
    return 0;
}
