/*  review8.c  --  Go west, young man!  
 *8．假设用户输入的是Go west, young man!，
 下面各程序的输出是什么？​
 （在ASCII码中，!紧跟在空格字符后面)
 */ 
#include <stdio.h>
int main(void) {
    printf("===  这是part a  ===\n");

    char ch;

    scanf("%c", &ch);
    while (ch != 'g') {
        printf("%c", ch);
        scanf("%c", &ch);
    }

    printf("===  这是part b   ===\n");

    scanf("%c", &ch);
    while (ch != 'g') {
        printf("%c", ++ch);
        scanf("%c", &ch);
    }
    printf("===  这是part c  ===\n");

    do {
        scanf("%c", &ch);
        printf("%c", ch);
    }while (ch != 'g');
    printf("===  这是part d  ===\n");
    
    scanf("%c", &ch);
    for (ch = '$' ; ch != 'g'; scanf("%c", &ch)) {
        printf("%c", ch);
    }
    return 0;
}
