#include <stdio.h>
int main()
{
	int i,j;
	int a[10][10];
	a[0][0]=1;
	for (i=1;i<=9;i++)
	{
		a[i][0]=1;
		if (i>1)
		    for (j=1;j<=i-1;j++)
		    	a[i][j]=a[i-1][j-1]+a[i-1][j];
		a[i][i]=1;
	}
	for (i=0;i<=9;i++)
	{
		for (j=0;j<=i;j++)	
		    printf(" %d ",a[i][j]);
		printf("\n");
	}
	return 0;
}
	
		