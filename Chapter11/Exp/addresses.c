/*  addresses.c  --  字符串的地址  */

#include <stdio.h>
#define MSG "I am special"

int main(void)
{

    char ar[] = MSG;
    const char *pt = MSG;
    printf("address of \"I'm special\":%p \n", "I'm special");
    printf("        address ar:%5p\n", ar);
    printf("        address pt:%5p\n", pt);
    printf("        address of MSG:%5p\n", MSG);
    printf("address of \"I'm special\": %5p \n", "I'm special");


    return 0;
}