#include <stdio.h>
int main()
{
	printf("输入5位数\n");
	int a,b,c,d,e;
	scanf("%1d%1d%1d%1d%1d",&a,&b,&c,&d,&e);
	a=(a+6)%8;
	b=(b+6)%8;
	c=(c+6)%8;
	d=(d+6)%8;
	e=(e+6)%8;
	printf("%d%d%d%d%d",e,d,c,b,a);
	return 0;
}