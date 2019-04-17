#include <stdio.h>
int main(void)
{
	printf("请输入一个不多于5位的整数\n");
	int a[4],b;
	int i;
	scanf("%d\n",b);
	printf("%d\n",b);
	while (b!=0)
	{
		a[i]=b%10;
	    printf("%d\n");
	    b/=10;
	    i++;
	}
	while (i>4)
	{
		printf("%d",a[i]);
		i++;
	}
    return 0;
}
