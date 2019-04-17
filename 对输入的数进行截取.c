#include <stdio.h>
int main(void)
{
	int ID;
	printf("**************************\n***请输入您的身份号***\n**************************\n");
	scanf("%*6d%4d\n",&ID);
	printf("%d\n",ID);
	return 0;
}