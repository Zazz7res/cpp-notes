#include <stdio.h>
int main(void)
{
    int num;
    printf("请输入一个整数：\n");
    scanf("%d", &num);


    int n = 0;
    while (n <= 10) 
    {
        printf("%d\t", num + n);
        n++;


    }



    return 0;

}
