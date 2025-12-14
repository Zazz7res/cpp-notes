/*  1．设计一个函数min(x, y)，
返回两个double类型值的较小值。
在一个简单的驱动程序中测试该函数。  */


#include <stdio.h>

double min(double x, double y);

int main(void)
{

    
    double x, y;
    
    printf("请输入两个double类型数值:\n");
    scanf("%lf %lf", &x, &y);
    printf("两个数值中最小的是: %lf\n", min(x, y));


    return 0;
}

double min(double x, double y)
{

    if (x < y)
        return x;
    else 
        return y;


}