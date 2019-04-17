#include <stdio.h>
int main()
{
	int fac(int n);
	long int s=0,n=20,a=1;
	while (a<=20)
	{
		s=s+fac(a);
		a++;
	}
	printf("%ld",s);
	return 0;
}
int fac(int n)
{
	int i=1,s=1;
	while (i<=n)
	{
		s=s*i;
		i++;
	}
	return(s);
}
	