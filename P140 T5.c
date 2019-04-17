#include <stdio.h>
int main()
{
    long int s=0,a,i=1,n,b;
	printf("请输入a,n并用逗号隔开\n");
	scanf("%d,%d",&a,&n);
	b=a;
	while (i<=n)
	{
		s+=a;
		a=a*10+b;
		i++;
	}
	printf("%ld",s);
	return 0;
}
		
		
	
	