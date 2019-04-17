#include <stdio.h>
void sort(int *p,int a[10])
{
	int t,*q,*max=NULL;
	for (p=a;p<=a+9;p++)
	{
		max=p;
		for (q=p;q<=a+9;q++)
		    if(*q>*max) max=q;	
		t=*p; *p=*max; *max=t;
	}	
}
int main()
{
	int a[10],i,*p;
	for (p=a;p<=a+9;p++)
	    scanf("%d",p);
	sort(p,a);
	for (p=a;p<=a+9;p++)
	    printf("%d  ",*p);
	return 0;
}