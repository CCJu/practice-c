#include <stdio.h>
int main()
{
	int fac(int n);
	int n,i,s=0;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		s+=fac(i);
	printf("%d",s);
	return 0;
}
int fac(int n)
{
	int s=1,i;
	for (i=1;i<=n;i++)
		s*=i;
	return(s);
}