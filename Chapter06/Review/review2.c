/*  测试for循环  */ 
#include <stdio.h>
int main(void) {
    int value;

    for (value = 36; value > 0; value /= 2) {
        printf("%3d", value);
    }
    return 0;
}
