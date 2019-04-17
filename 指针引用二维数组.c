#include <stdio.h>
int main()
{
	int a[4][4],i,j;
	int (*p)[4]=&a;
	for (i=0;i<=3;i++)
		for (j=0;j<=3;j++)
		    scanf("%d",*(p+i)+j);
	for (i=0;i<=3;i++)
		for (j=0;j<=3;j++)
		    printf("%d\n",*(*(p+i)+j));
	return 0;
}