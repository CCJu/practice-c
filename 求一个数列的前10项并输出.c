#include <stdio.h>
int main()
{
	int a[10],i;
	a[0]=2;
	a[1]=3;
	for (i=2;i<=9;i++)
	    a[i]=a[i-1]+a[i-2];
	for (i=0;i<=9;i++)
	    printf("a[%d]=%d\n",i,a[i]);
	return 0;
}
	