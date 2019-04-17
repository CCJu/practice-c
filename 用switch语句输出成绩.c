#include <stdio.h>
int main(void)
{
	int a;
	printf("请输入今天是星期几？\n",a);
	scanf("%d",&a);
	switch(a)
	{
	    case 1:
	    case 2:
	    case 3:
	    case 4:
	    case 5:printf("上课");break ;
	    case 6:
	    case 7:printf("自由活动");break;
	}
	return 0;
}