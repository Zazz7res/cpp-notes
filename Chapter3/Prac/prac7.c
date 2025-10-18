//  身高转换
#include <stdio.h>
#define Inchs 2.54

int main(void)
{
	float a, b;
	printf("请输入你的身高:\n");
	while (scanf(" %f", &a) == 1)
	{
	
		b = Inchs * a;
		printf("转换成英寸是:%f\n", b);
		printf("请输入你的身高:\n");

	       	
	
	
	}



	return 0;

}
