/*  2．设计一个函数chline(ch, i, j)，
打印指定的字符j行i列。
在一个简单的驱动程序中测试该函数。*/
//比如说打印一个字符a，5行 x 6列

#include <stdio.h>
#include <string.h>

char chline(char ch, int i, int j);


int main(void)
{
    char ch;
    int i, j;

    printf("请输入你所要打印的字符:\n");
    scanf("%c", &ch);
    printf("请输入你所要打印的行数和列数:\n");
    scanf("%d %d", &i, &j);
    printf("你所要打印的字符阵列式:\n");
    chline(ch, i, j);




    return 0;
}


char chline(char ch, int i, int j)
{

    int a, b;
    for (a = 0; a < j; a++)
    {

        for (b = 0; b < i; b++)
            printf("%c", ch);
        printf("\n");
    }
        
            



}