//   现在使用getchar()实现读取一个字符
#include <stdio.h>


int main(void)
{

	char ch;


	printf("请输入一个字符:\n");
	while ((ch = getchar()) != EOF)  //这里很重  sdf//这里很重要的要的
	{
		if (ch == '\n') //这里很重要的
			continue;
		printf("你输入的字符是:%c\n", ch);
		printf("请你输入一个字符:\n");

	
	
	}




	return 0;
}
