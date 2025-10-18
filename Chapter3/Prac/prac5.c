//  输入年龄转换成秒数
#include <stdio.h>
#define Year 365
#define Hour 24
#define Minute 60

int main(void)
{
	int age;
	double seconds;


	printf("请输入你的年龄:\n");
	while(scanf(" %d", &age)){
	seconds = age * Year * Hour * Minute;
	printf("你的年龄转换成秒数是:%lf seconds.\n", seconds);	
	printf("请输入你的年龄:\n");
	}


	return 0;

}
