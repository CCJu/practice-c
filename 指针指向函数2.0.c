#include <stdio.h>
int max(int x,int y)
{ return(x>y?x:y);}
int min(int x,int y)
{ return(x<y?x:y);}
int add(int x,int y)
{ return(x+y);}
void fun(int x,int y,int z)
{
	int (*p)(int,int);
	if(z==1) {p=max; printf("%d",max(x,y));}
	if(z==2) {p=min; printf("%d",min(x,y));}
	if(z==3) {p=add; printf("%d",add(x,y));}
}
int main()
{
	int x,y,z;
	printf("请输入需要操作的两个整数\n");
	printf("请在需处理的数字后输入需执行的功能。\n1为求最大，2为求最小，3为二者相加\n");
	scanf("%d%d%d",&x,&y,&z);
	fun(x,y,z);
	return 0;
}