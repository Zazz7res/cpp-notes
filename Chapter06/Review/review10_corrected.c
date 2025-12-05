#include <stdio.h>
#define SIZE 8
int main(void) {
    int by_tows[SIZE] = {0};
    int index;

    for (index = 1; index <= SIZE;  index++) {
        by_tows[index] = 2 * index;
    }

    for (index = 1; index <= SIZE; index++) {
        printf("%d", by_tows[index]);    
    }
    printf("\n");

    return 0;
}
