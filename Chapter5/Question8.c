#include <stdio.h>


int main(void)
{

    int num1, num2;


    printf("This program computers moduli.\n");
    printf("Enter an integer to serve as the second operand:\n");
    scanf("%d", &num1);
    printf("Now enter the first operan:\n");
    scanf("%d", &num2);
    printf("%d %% %d is %d\n", num2, num1, num2 % num1);
    printf("Enter next number for first operand"
           " (<= 0 to quit):\n");
    while((scanf("%d", &num2)) == 1 && num2 >0)
    {
        printf("%d %% %d is %d\n", num2, num1, num2 % num1);
        printf("Enter next number for first operand"
           " (<= 0 to quit):\n");


    }



    return 0;


}


