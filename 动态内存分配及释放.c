#include <stdio.h>
#include <stdlib.h>
void check(double *p,int n)
{
	double *pt=p;
	for(;pt<p+n;pt++)
	    if(*pt<60) printf("%.3f\n",*pt);
}
int main()
{
	int i=1;
	double *pt=(double * )malloc(5);
	for(;i<=5;i++)
	    scanf("%lf",pt+i);
	check(pt,5);
	free(pt);
	return 0;
}