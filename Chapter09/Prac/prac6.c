/* 
 * 6．编写并测试一个函数，该函数以3个double变量的地址作为参数，把最小值放入第1个变量，
 * 中间值放入第2个变量，最大值放入第3个变量。
*/ 
#include <math.h>
#include <stdio.h>

void sortThree(double *x, double *y, double *z);

int main(void) {
    double x, y, z;

    printf("请输入三个 double 类型的数字：\n");
    scanf("%lf %lf %lf", &x, &y, &z);
    printf("x = %lf, y = %lf, z = %lf\n", x, y, z);
    sortThree(&x, &y, &z);
    printf("x = %lf, y = %lf, z = %lf\n", x, y, z);
}

void sortThree(double *x, double *y, double *z) {
    double temp;

    //  第一步：确保*x <= 
    if (*x > *y) {
        temp = *x;
        *x = *y;
        *y = temp;
    }

    //此时，*x 是 *x 和 *y 中的最小值
    
    //第二步：确保*x <= *z(这样*x 就是三个数中的最小值)
    if (*x > *z) {
        temp = *x;
        *x = *z;
        *z = temp;
    }

    //第三步：确保*y <= z (这样 *y 是剩余两个数中的较小值)
    if (*y > *z) {
        temp = *y;
        *y = *z;
        *z = temp;
    }
}
