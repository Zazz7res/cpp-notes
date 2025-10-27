/*

编写一个程序，先提示用户输入名，然后提示用户输入姓。
在一行打印用户输入的名和姓，下一行分别打印名和姓的字母数。
字母数要与相应名和姓的结尾对齐，如下所示：
Melissa Honeybee
      7        8
接下来，再打印相同的信息，但是字母个数与相应名和姓的开头对齐，如下所示：
Melissa Honeybee
7       8


*/


#include <stdio.h>
#include <string.h>


int main(void)
{

    char first_name[30];
    char last_name[30];

    printf("请输入名字:\n");
    scanf("%s", first_name);
    printf("请输入姓氏:\n");
    scanf("%s", last_name);

    printf("%s %s\n",first_name, last_name);
    for (int i = 0; i < strlen(first_name) - 1; i++)  //strlen返回值是size_t类型，测量的是字符的个数
        printf(" ");
    printf("%d", (int)strlen(first_name));
    for (int i = 0; i <strlen(last_name); i++)
        printf(" ");
    printf("%d\n", (int)strlen(last_name));


    return 0;
}