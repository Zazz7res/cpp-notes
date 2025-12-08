#include <stdio.h>
void Smile(void);

int main(void) {
    for (int i = 0; i < 3; i++) {
        Smile();
    }
    printf("\n");
    for (int i = 0; i < 2; i++) {
        Smile();
    }
    printf("\n");
    Smile();
    printf("\n");
    return 0;
}

void Smile(void) {
    printf("Smile!");
}
