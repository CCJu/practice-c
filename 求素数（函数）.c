#include <stdio.h>
int main()
{
	int n;
	int pr(int x);
	for (n=200;n<=300;n++)
		if(pr(n)==1) printf("%d\n",n);
	return 0;	
}
int pr(int x)
{
	int i,flase=1;
	for (i=2;i<x;i++)
		if (x%i==0) 
		{
			flase=0;
			break;
	     }
	return(flase);
}
		