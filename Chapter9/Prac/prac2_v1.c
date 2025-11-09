/*  2．设计一个函数chline(ch, i, j)，
    打印指定的字符j行i列。
    在一个简单的驱动程序中测试该函数。  */

#include <stdio.h>
void chline(char ch, int i, int j);


int main(void)
{
    char ch;
    int i, j;
    
    printf("请输入一个字符:\n");
    scanf("%c", &ch);
    printf("请输入行数和列数:\n");
    scanf("%d %d", &i, &j);
    chline(ch, i, j);

    return 0;
}


void chline(char ch, int i, int j)
{
    int a, b;

    for (a = 0; a < i; a++)
    {
        for (b = 0; b < j; b++)
        {
            printf("%c", ch);

        }     
        printf("\n");
    }
}