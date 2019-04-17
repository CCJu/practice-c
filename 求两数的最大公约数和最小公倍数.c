#include <stdio.h>
int main()
{
	int m,n,i;
	printf("请输入两个正整数,并用逗号隔开\n");
	scanf("%d,%d",&m,&n);
	if (m>n) i=n;
	else i=m;
	while (!(m%i==0&&n%i==0)) i--;
	printf("m,n的最大公约数为%d\n",i);
	printf("m,n的最小公倍数为%d\n",n*m/i);
	return 0;
}