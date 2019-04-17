#include <stdio.h>
int main(void)
{
    int a,i=0;
    scanf("%d",&a);
    printf("请输入一个不大于5位的整数\n");
    printf("%d\n",a);
    while (a!=0)
    {
    	printf("%d\n",a%10);
    	a/=10;
    	i++;
    }
    printf("此整数为%d位数",i);
    return 0;
}
    	