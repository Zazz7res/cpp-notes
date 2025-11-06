/*  pnt_add.c  --  指针地址  */
#include <stdio.h>
#define SIZE 4


int main(void)
{

    short dates[SIZE];
    short * pti;
    short index;
    double bills[SIZE];
    double * ptf;
    pti = dates;
    ptf = bills;
    printf("%23s %15s\n", "short", "double");
    for (index = 0; index < SIZE; index++)
    {
        printf("pointers + %d: %10p %15p\n", index, pti + index, ptf + index);


        
    }


    return 0;
}

//double * const pc = rates;  //pc这个指针不允许指向别处
//但是他可以修改rates数组中的值
//const double * cp = rates;  //cp这个指针可以指向别处
//但是不允许通过cp修改rates数组中的值
//const double * const cpc = rates; //cpc这个指针不允许指
//向别处,也不允许通过cpc修改rates数组中的值
