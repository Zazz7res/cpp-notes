/*  review5.c  --  有问题的代码  */ 
#include <stdio.h>
int main(void) {
    int i, j, list(10);                 // 这里的list应该是一个数组
    for (i = 1, i < 10, i++) {          // 这里应该使用分号
        list[i] = 2 * i + 3;
        for (j = 1, j >= i, j++) {      // 这里应该使用分号
                                        //
            printf(" %d", list[j]);
        printf("\n");
        
    // 这里少了花括号
    return 0;
}
