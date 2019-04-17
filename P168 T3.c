#include <stdio.h>
int main()
{
	int a[3][3];
	int i=0,j=0;
    for (i=0,j=0;;j++)
	{
		if (j>2&&i!=2) i++,j=0;
		if (j==3) break;
		scanf("%d",&a[i][j]);
	}
	printf("%d\n",a[0][0]+a[1][1]+a[2][2]);	      printf("%d",a[2][0]+a[1][1]+a[0][2]);
	return 0;
}
		