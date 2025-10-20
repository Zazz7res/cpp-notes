/*  for review2.c  */
#include <stdio.h>
#define Q "His Hamlet was funny without being vulgal."

int main(void)
{
    printf("He sold the painting for $%2.2f.\n", 2.345e2);
    printf("%c%c%c\n", 'H', 105, '\41');
    printf("%s\nhas %lu characters.\n", Q, strlen(Q));
    printf("ls %2.2e the same as %2.2f?\n", 1201.0, 1201.0);


    return 0;

}
