#include <stdio.h>
int main()
{
	int m,n;
	int fac(int m);
	scanf("%d%d",&m,&n);
	printf("%.4f",fac(n)*1.0/(fac(m)*fac(n-m)));
	return 0;
}
int fac(int m)
{
	int i,s=1;
	for(i=1;i<=m;i++)
	    s*=i;
	return(s);
}