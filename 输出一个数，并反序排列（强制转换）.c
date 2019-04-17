#include <stdio.h>
int main(void)
{
	printf("请输入一个不多于5位的整数\n");
    int i;
    int a,b,c,d,e;
	scanf("%d",&i);
	if (i>=10000)
	{
		printf("此整数为5位数\n");
		a=(int)(i/10000.0);
		b=(int)((i/10000.0-a)*10);
		c=(int)(i/100.0-a*100-b*10);
		d=(int)(i/10.0-a*1000-b*100-c*10);
		e=i-a*10000-b*1000-c*100-d*10;
		printf("%d,%d,%d,%d,%d\n",a,b,c,d,e);
		printf("%d%d%d%d%d\n",e,d,c,b,a);
	}
	else if (i>=1000)
	{
		printf("此整数为4位数");
		a=(int)(i/1000.0);
		b=(int)((i/1000.0-a)*10);
		c=(int)(i/10.0-a*100-b*10);
		d=i-a*1000-b*100-c*10;
		printf("%d,%d,%d,%d\n",a,b,c,d);
		printf("%d%d%d%d",d,c,b,a);
	}
	else if (i>=100)
	{
		printf("此整数为3位数");
		a=(int)(i/100.0);
		b=(int)(i/10.0-a*10);
		c=i-a*100-b*10;
		printf("%d,%d,%d\n",a,b,c);
		printf("%d%d%d",c,b,a);
	}
	else if (i>=10)
	{
		printf("此整数为2位数");
		a=(int)(i/10);
		b=i-a*10;
		printf("%d,%d\n",a,b);
		printf("%d%d",b,a);
	}
	else
	{
		printf("此整数为1位数");
		printf("%d\n",i);
		printf("%d",i);
	}
	return 0;
}