//  编写一个程序，提示用户输入名和姓，然后以“名,姓”的格式打印出来。
#include <stdio.h>


int main(void)
{

     // 增大数组容量（建议至少20-50字符）
    char first_name[50];
    char last_name[50];

    /*char first_name[5];
    char last_name[5];*/
    
 

    printf("请输入你的名字:\n");  //原来这里要这样处理的啊，我都忘了有%s这个占位符了，我之前错误地使用了%c和while循环的搭配
    scanf("%49s", first_name);
    // 限制读取49字符（留1字节给\0）
    //scanf("%5s", first_name);
    printf("请输入你的姓氏:\n");
    scanf("%49s", last_name);
    //scanf("%5s", last_name);

    printf("%s, %s\n", first_name, last_name);





    return 0;
}