//使用scanf()实现读取一个字符


#include <stdio.h>
int main(void)
{
	char ch;
	printf("请输入一个字符：\n");
	while (scanf(" %c", &ch) == 1)
	{
		printf("你输入的字符是这个：%c\n", ch);
		printf("请输入一个字符:");
	
	
	
	}

	return 0;


}
