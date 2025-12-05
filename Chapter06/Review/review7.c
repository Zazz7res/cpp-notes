/*  review7.c  --  打印什么内容？  */ 
#include <stdio.h>

int main(void)
{
    printf("=== 这是part a ===\n");
    int i = 0;
    while (++i < 4) {
        printf("Hi  ");
    } do {
            printf("Bye!    ");
    }while (i++ < 8);

    printf("=== 这是part b===\n");

    char ch;

    for (i = 0,  ch = 'A'; i < 4; i++, ch+= 2 * i) {
        printf("%c", ch);
    }

    return 0;
}
