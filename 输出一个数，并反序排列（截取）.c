#include <stdio.h>
int main(void)
{
	printf("请输入一个不多于5位的整数两次并用逗号隔开\n");
	printf("\n如果是4位数的话，请在第二次输入的时候在最后补一个0，三位数补两个0，两位数补三个0，1位数补4个0\n");
	int i,a,b,c,d,e;
	scanf("%d,%1d%1d%1d%1d%1d",&i,&a,&b,&c,&d,&e);
	if (i>=10000)
	{
		printf("此整数为5位数\n");
		printf("%d,%d,%d,%d,%d\n",a,b,c,d,e);
		printf("%d%d%d%d%d",e,d,c,b,a);
	}
	else if (i>=1000)
	{
		printf("此整数为4位数\n");
		printf("%d,%d,%d,%d\n",a,b,c,d);
		printf("%d%d%d%d",d,c,b,a);
	}
	else if (i>=100)
	{
		printf("此整数为3位数\n");
		printf("%d,%d,%d\n",a,b,c);
		printf("%d%d%d",c,b,a);
	}
	else if (i>=10)
	{
		printf("此整数为2位数\n");
		printf("%d,%d\n",a,b);
		printf("%d%d",b,a);
	}
	else
    {
    	printf("此整数为1位数\n");
    	printf("%d\n",a);
    	printf("%d\n",a);
    }
	return 0;
}