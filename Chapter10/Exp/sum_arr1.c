//  sum_arr1.c  --  数组元素之和
//  如果编译器不支持 %zd，用 %u 或者 %lu 替代它
#include <stdio.h>
#define SIZE 10
int sum(int ar[], int n);   //  这是一个指针，在函数原型可以这样使用int ar[] | int [] | int * ar | int * 
                            //  这些都是等价的

int main(void) {
    int marbles[SIZE] = { 20, 10, 5, 39, 4, 16, 19, 26, 31, 20 };
    long answer;

    answer = sum(marbles, SIZE);
    printf("The total number of marbles is %ld.\n", answer);
    printf("The size of marbles is %zd bytes.\n", sizeof marbles);

    return 0;
}

int sum(int ar[], int n) {
    int i;
    int total = 0;

    for (i = 0; i < n; i++) {
        total += ar[i];
    }
    printf("The size of ar is %zd bytes.\n", sizeof ar);

    return total;
}
