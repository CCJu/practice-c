#include <stdio.h>
int main()
{
	printf("请输入一个整数\n");
	int n,i,m;
	int a[6]={7,12,14,16,19};
	scanf("%d",&n);
	for (i=0;i<=4;i++)
	{
		if (n>=a[i]) 
		{
			printf("%d\n",i);
			break;
		}
	}
	for  (m=5;m>=i;m--)
	{
		a[m]=a[m-1];
	}
	a[i]=n;
	for (i=0;i<=5;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
	