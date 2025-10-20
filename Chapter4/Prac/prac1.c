//  practice name
#include <stdio.h>


int main(void)
{

    char first_name[10];
    char last_name[10];

    printf("请输入你的first_name:\n");
    for (int i = 0; i < 10; i++) 
    {
      
        scanf("%c", &first_name[i]);
    }
    printf("请输入你的last_name:\n");
    for (int i = 0; i < 10; i++)
        scanf("%c", &last_name[i]);
    printf("你的last_name:\n");
    for (int i = 0; i < 10; i++)
        printf("%c", last_name[i]);
    printf("你的first_name:\n");
    for (int i = 0; i < 10; i++)
        printf("%c", first_name[i]);
    
       

    return 0;

}
