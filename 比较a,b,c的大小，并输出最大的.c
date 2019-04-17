#include <stdio.h>
int main(void)
{
	int a,b,c,d;
	scanf("%d,%d,%d",a,b,c);
	d=a;
	if (d<b)
	{
		d=b;
	}
	if (d<c)
	{
		d=c;
	}
	printf("max=%d",d);
	return 0;
}