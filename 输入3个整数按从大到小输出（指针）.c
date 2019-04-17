#include <stdio.h>
int main()
{
	int a[3],i,t;
	int *j=a;
	for (i=0;i<=2;i++)
	    scanf("%d",&a[i]);
	for (i=0;i<=2;i++)
	    if (i<=1)
	        if (a[i]>a[i+1])
	        {
	        	t=a[i];
	        	a[i]=a[i+1];
	        	a[i+1]=t;
	        }	
    for (i=0;i<=2;i++)
        printf("%d\n",*(j+i));
	return 0;
}