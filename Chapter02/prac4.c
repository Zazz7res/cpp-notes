#include <stdio.h>
#define FELLOW "For he's a jolly good fellow!"
void jolly(void); 
void deny(void);

int main(void) {
    jolly();
    deny();
    return 0;
}

void jolly(void) {
    for (int i = 0; i < 3; i++) {
        printf("%s\n", FELLOW);
    }
}

void deny(void) {
    printf("Which nobydy can deny!\n");
}
