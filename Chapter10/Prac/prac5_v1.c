/*  5．编写一个函数，
返回存储在double类型数组中最大值和最小值的差值，
并在一个简单的程序中测试该函数。  */

#include <stdio.h>
#define NUM 10
double diff(double * arr, int n);


int main(void)
{
    double arr[NUM] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    double result = diff(arr, NUM);
    printf("%lf", result);

    return 0;
}


double diff(double * arr, int n)
{
    double max = 0, min = 0;
    for (int i = 0; i < n; i++)
        {
            if (arr[i] > max)
                max = arr[i];
            if (arr[i] < min)
                min = arr[i];

        }
        return max - min;

}