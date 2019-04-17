#include <stdio.h>
int max(int x,int y)
{
	return(x>y?x:y);
}
int main()
{
	int a,b,c;
	int (*p)(int,int);
	scanf("%d%d",&a,&b);
	p=max;
	c=(*p)(a,b);
	printf("%d",c);
	return 0;
}
	