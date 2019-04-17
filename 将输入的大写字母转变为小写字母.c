#include <stdio.h>
int main()
{
	char a;
	printf("请输入任意的一个大写字母\n");
	a=getchar();
	a=a+32;
	putchar(a);
	return 0;
}