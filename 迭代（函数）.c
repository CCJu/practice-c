#include <stdio.h>
int main()
{
	float n,x,c;
	char p(float n,float x);
	scanf("%f %f",&n,&x);
	c=p(n,x);
	printf("%f",c);
	return 0;
}
char p(float n,float x)
{
	if (n==0) return(1);
	if (n==1) return(x);
	if (n>1) 
	return((2*n-1)*x-p(n-1,x)-(n-1)*p(n-2,x)/n);
}
	