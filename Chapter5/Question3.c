#include <stdio.h>
#define WeekDay 7


int main(void)
{
    int total_days, weeks, days;
    printf("请输入天数:\n");
    while (scanf("%d", &total_days) == 1 && total_days > 0)
    {
    weeks = total_days / WeekDay; 
    days = total_days % WeekDay;
    printf("结果:  %d days are %d weeks, %d days\n", total_days, weeks, days);
    
    printf("请输入天数:\n");


    }

    printf("输入错误，退出!\n");






    return 0;

}


