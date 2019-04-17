#include <stdio.h>
int main()
{
	char p(float n);
	float n;
	scanf("%f",&n);
	printf("%f",p(n));
	return 0;
}
char p(float n)
{
	float c;
	if (n==0) c=1;
	if (n==1) c=3;
    if (n>1)
	    c=(2*n-1)*3-p(n-1)-(n-1)*p(n-2)/n;
    return(c);
}
	