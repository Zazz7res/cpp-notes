/*  1．编写一个程序，创建一个包含26个元素的数组，
 *  并在其中存储26个小写字母。然后打印数组的所有内容。
 */ 
#include <stdio.h>

int main(void) {

    char letter[26] = {'a'};

    for (int i = 0; i < 27; i++) {
        letter[i] = 'a' + i;
    }
    
    for (int i = 0; i < 27; i++) {

        printf("%c", letter[i]);

        }

    return 0;
}
