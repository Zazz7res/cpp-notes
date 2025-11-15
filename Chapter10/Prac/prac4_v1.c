/* 4．编写一个函数，返回存储在double类型数组中最大值的下标，
并在一个简单的程序中测试该函数。 */

#include <stdio.h>

int turn_back(double * arr,int n);


int main(void)
{

    double arr[10] = {  5, 4, 7, 1, 2, 3, 6 };
    printf("%d", turn_back(arr, 10));

    return 0;
}

int turn_back(double *arr, int n)
{
    int a = 0;
    int result = 0;
    for (int i = 0; i < n; i++)
    {

        if (arr[i] > a)
        {
            a = arr[i];
            result = i;
            
        }

        return result;

    }
    
}
