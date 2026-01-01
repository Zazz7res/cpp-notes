/*  3．编写一个函数，接受3个参数：
    一个字符和两个整数。字符参数是待打印的字符，
    第1个整数指定一行中打印字符的次数，
    第2个整数指定打印指定字符的行数。
    编写一个调用该函数的程序。*/

#include <stdio.h>
void chline2(char ch, int a, int b);


int main(void)
{
    char ch;
    int a, b;

    printf("请输入一个字符:\n");
    scanf("%c", &ch);
    printf("请输入第一行打印的个数:\n");
    scanf("%d", &a);
    printf("请输入打印的行数:\n");
    scanf("%d", &b);
    chline2(ch, a, b);
    
    return 0;
}


void chline2(char ch, int a, int b)
{
    int i, j;
    for (i = 0; i < a; i++)
        printf("%c", ch);
    for (i = 0; i < b; i++)
    {
        printf("%c", ch);
        printf("\n");
    }
}