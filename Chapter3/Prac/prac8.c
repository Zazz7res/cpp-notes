/* 1a = 2b
 * 1b = 8c
 * 1c = 2d
 * 1d = 3e   */

#include <stdio.h>


int main(void)
{


	float a, b, c, d, e;

	printf("请输入c的数量:\n");
	while (scanf(" %f", &b) == 1)
	{
		a = b / 2;
		c = b * 8;
		d = c * 2;
		e = d * 3;
		printf("a = %f\n", a);
		printf("c = %f\n", c);
		printf("d = %f\n", d);
		printf("e = %f\n", e);
   		printf("请输入c的数量:\n");	
	
	}



	return 0;

}
