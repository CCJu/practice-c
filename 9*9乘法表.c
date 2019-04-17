#include <stdio.h>
int main()
{
	int a=9,j,k;
	for (j=0;j<=a;j++)
	{
		for (k=1;k<=a;k++)
		{
			printf("%d*%d=%d  ",a,k,a*k);
		}
		j=0;
		a--;
		printf("\n");
	}
	return 0;
}
 