#include <stdio.h>
int main(void)
{
    printf("功能:输出三个实数中的最大量\n");
	printf("请输入三个实数并用空格隔开\n");
	int max(int x,int y);
    int a,b,c,d;
	scanf("%d%d%d",&a,&b,&c);
	d=max ( max (a,b) ,c);
	printf("max =%d\n",d);
    return 0;
}
int max(int x,int y)
{
	int z;
	if(x>y)
	{
		z = x;
	} else (z =y);
	return(z);
}