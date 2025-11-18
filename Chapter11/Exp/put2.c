/*  put2.c  --  print a string and count number  */
#include <stdio.h>
void put1(const char *);
int put2(const char *);

int main(void)
{

    put1("If I'd as much mokny");
    put1(" as I could speed,\n");
    printf("I count %d characters.\n", 
            put2("I never would cry old chairs to mend."));
    return 0;


}

void put1(const char * string)
{
    while (*string)
        putchar(*string++);

}

int put2(const char * string)
{
    int count = 0;
    while (*string)
    {
        putchar(*string++);
        count++;
    }
    putchar('\n');

    return(count);



}
