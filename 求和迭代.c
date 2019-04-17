#include <stdio.h>
int main()
{
	int a,i,s=0;
	int num(int i);
	scanf("%d",&i);
	for (a=1;a<=i;a++)
	    s+=num(a);
	printf("%d",s);
	return 0;
}
int num(int i)
{
	int c;
	if (i=1) 
	    c=1;
	else
	    c=num(i-1)+1;
	return(c);
}
	