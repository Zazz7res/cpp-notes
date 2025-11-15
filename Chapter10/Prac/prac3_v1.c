/*  3．编写一个函数，返回存储在int类型数组中的最大值，
并在一个简单的程序中测试该函数。*/

#include <stdio.h>

#define NUM 20
int turn_back_max(int * arr);


int main(void)
{
    int arr[NUM] = {0};

    for (int i = 0; i < NUM; i++)
        { 
            arr[i] = i + 3;
            printf("%5d", arr[i]);
        }
    int a = turn_back_max(arr);
    printf("\n数组arr的最大值是:%d", a);
    return 0;
}


int turn_back_max(int *arr)
{
    int a = 0;  //这里要注意初始化，尤其是比较的时候。
    for (int i = 0; i < NUM; i++)
    {
        if (a < arr[i])
            a = arr[i];
        printf("%5d", a);
    }
    return a;

}