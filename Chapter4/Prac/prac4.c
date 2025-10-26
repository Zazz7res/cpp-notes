/*

4．编写一个程序，提示用户输入身高（单位：英寸）和姓名，
然后以下面的格式显示用户刚输入的信息：
Dabney, you are 6.208 feet tall
使用float类型，并用/作为除号。如果你愿意，可以要求用户以厘米为单位输入身高，
并以米为单位显示出来。

*/

#include <stdio.h>
int main(void)
{

    float height_in_inches;
    char name[50];

    printf("请输入你的名字:\n");
    scanf("%49s", name);
    printf("请输入你的身高 (单位:英寸):\n");
    scanf("%f", &height_in_inches);
    float height_in_feet = height_in_inches / 12.0f;

    printf("%s, you are %.3f feet tall\n", name, height_in_feet);
    



    return 0;
}