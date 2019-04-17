#include <stdio.h>
int main(void)
{
	int a,b,c,i,d;
	for (i=100;i<1000;i++)
	{
		a=(int)(i/100.0);
		b=(int)(i/10.0-a*10);
		c=i-a*100-b*10;
		d=a*a*a+b*b*b+c*c*c;
		if (i==d)
		{
			printf("水仙花数:%d\n",i);
		}
	}
	return 0;
}