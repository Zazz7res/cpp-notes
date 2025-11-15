/*  2．编写一个程序，初始化一个double类型的数组，
然后把该数组的内容拷贝至3个其他数组中（在main()中声明这4个数组）​。
1. 使用带数组表示法的函数进行第1份拷贝。
2. 使用带指针表示法和指针递增的函数进行第2份拷贝。把目标数组名、源数组名和待拷贝的元素个数作为前两个函数的参数。
3. 第3个函数以目标数组名、源数组名和指向源数组最后一个元素后面的元素的指针。
也就是说，给定以下声明，则函数调用如下所示：
double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
double target1[5];
double target2[5];
double target3[5];
copy_arr(target1, source, 5);
copy_ptr(target2, source, 5);

copy_ptrs(target3, source, source + 5);*/

#include <stdio.h>

void copy_arr(double target1[5], double source[5], int num);
void copy_ptr(double * target2, double *source, int n);
void copy_ptrs(double * target3, double * source, double * end);
void PrintArr(double * pt, int n);

int main(void)
{

    double source[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    double target1[5];
    double target2[5];
    double target3[5];

    double * pt = &source[5];

    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, pt);

    printf("现在输出结果:\n");
    printf("copy_arr的结果:\n");
    PrintArr(target1, 5);
    printf("copy_ptr的结果:\n");
        PrintArr(target2, 5);
    printf("copy_ptrs的结果:\n");
        PrintArr(target3, 5);
    return 0;
}

void copy_arr(double target1[5], double source[5], int n)
{

    for (int i = 0; i < n; i++)
        target1[i] = source[i];

}   

void copy_ptr(double * target2, double * source, int n)
{
    for (int i = 0; i < n; i++, target2++, source++)
        *target2 = *source;


}

void copy_ptrs(double * target3, double * source, double * end)
{
    for (double *  begin = source; begin < end; begin++, target3++, source++)
        *target3 = *source;


}

void PrintArr(double * pt, int n)
{
    for (int i = 0; i < n; i++)
        printf("%5.1lf", pt[i]);
    printf("\n");


}