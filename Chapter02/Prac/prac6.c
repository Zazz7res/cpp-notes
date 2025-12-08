/*
6．编写一个程序，创建一个整型变量toes
，并将toes设置为10。程序中还要计算toes的两倍和toes的平方
。该程序应打印3个值，并分别描述以示区分。
*/ 

#include <stdio.h>
int main(void) {
    int toes = 10;

    printf("        toe = 10.\n");
    printf("double toes = %d.\n", 2*toes);
    printf("  douL toes = %d.\n", toes*toes*toes);

    return 0;
}
