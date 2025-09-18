#include <stdio.h>


double cubic_value(double);

int main(void)
{


    double num;

    printf("请输入一个小数:\n");
    while (scanf("%lf", &num) == 1 && num > 0)
    {
        printf("%lf\n", cubic_value(num));
        
        printf("请输入一个小数:\n");
    }


    return 0;

}



double cubic_value(double n)
{

    return n * n * n;


}
