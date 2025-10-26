//  1．编写一个程序，提示用户输入名和姓，然后以“名,姓”的格式打印出来。
#include <stdio.h>
#include <string.h>


int main(void)
{

    char first_name[50];
    char last_name[50];


    printf("请输入你的名字:\n");
    fgets(first_name, sizeof(first_name), stdin);
    first_name[strcspn(first_name, "\n")] = '\0';  //  移除换行符

    printf("请输入你的姓氏:\n");
    fgets(last_name, sizeof(last_name), stdin);
    last_name[strcspn(last_name, "\n")] = '\0';  //  移除换行符


    printf("%s, %s\n", first_name, last_name);







    return 0;
}