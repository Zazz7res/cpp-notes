//  打印一个浮点数的多种形式
#include <stdio.h>


int main(void)
{

	double num = 64.25;
	printf("Enter a floating-point value: %.2f\n", num);
	printf("fixed-point notation: %f\n", num);
	printf("exponential notation: %e\n", num);
	printf("p notation: %a\n", num);


	return 0;

}
