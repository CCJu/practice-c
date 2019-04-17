#include <stdio.h>
int main()
{
	int j,k,s;
	int a[4][4];
	for (j=0,k=0;j<=3;k++)
	{
		if (k>3) k=0,j++;
		scanf("%d",&a[j][k]);
		if (k==3&&j==3) break;
	}
	s=a[0][0]+a[1][1]+a[2][2]+a[3][3];
	printf("对角线之和为%d\n",s);
	s=a[0][1]+a[0][2]+a[0][3]+a[1][2]+a[1][3]+a[2][3];
	printf("上三角元素和为%d",s);
	return 0;
}