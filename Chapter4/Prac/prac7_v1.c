/*

7．编写一个程序，将一个double类型的变量设置为1.0/3.0，
一个float类型的变量设置为1.0/3.0。分别显示两次计算的结果各3次：
一次显示小数点后面6位数字；一次显示小数点后面12位数字；
一次显示小数点后面16位数字。程序中要包含float.h头文件，
并显示FLT_DIG和DBL_DIG的值。1.0/3.0的值与这些值一致吗？

*/

#include <stdio.h>
#include <float.h>


int main(void)
{
    double A = 1.0 / 3.0;
    float B = 1.0 / 3.0;
    printf("double类型变量和float类型变量1.0/3.0的值:\n");
    printf("显示小数点后面6位数字:  double A = %.6lf, float B = %f\n", A, B);
    printf("显示小数点后面12位数字:  double A = %.12lf, float B = %.12f\n", A, B);
    printf("显示小数点后面16位数字:  double A = %.16lf, float B = %.16f\n", A, B);
    




    return 0;
}