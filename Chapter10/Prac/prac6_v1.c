/* 6．编写一个函数，把double类型数组中的数据倒序排列，并在一个简单的程序中测试该函数。 */
/*  哈哈哈，好傻逼，这里明明讲得是倒序，想了半天  */

#include <stdio.h>
#define NUM 10

void reverse(double * arr, double * end);
void print_arr(double * arr, int n);

int main(void)
{
    double arr[NUM] = { 3, 4, 5, 0, 1, 7, 8, 9, 2, 6 };
    print_arr(arr, NUM);
    reverse(arr, &arr[NUM -1]);
    printf("结果是:\n");
    print_arr(arr, NUM);

    return 0;
}

void reverse(double * arr, double * end)
{
    double tiz;
    for (; *arr < *end; arr++, end--)
        {
            if (arr < end)
            {
                tiz = *arr;
                *arr = *end;
                *end = tiz;
            }

        }



}


void print_arr(double * arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%5.1lf", arr[i]);


}
