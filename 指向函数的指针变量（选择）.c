#include <stdio.h>
int max(int x,int y)
{ return(x>y?x:y);}
int min(int x,int y)
{ return(x<y?x:y);}
int main()
{
	int a,b,c,n;
	int (*p)(int,int);
	printf("请输入两个整数，并选择求最大或是最小值，1为最大，2为最小\n");
	scanf("%d%d%d",&a,&b,&n);
	if (n==1) p=max;
	else p=min;
	c=(*p)(a,b);
	printf("%d",c);
	return 0;
}
	