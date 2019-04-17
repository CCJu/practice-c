#include <stdio.h>
int main()
{
	int a,b,c;
	int *m=&a,*n=&b;	
	scanf("%d%d",m,n);
	if (*m<*n)
	{
		c=*m;
	    *m=*n;
	    *n=c;
	}
	printf("%d %d",*m,*n);
	return 0;
}