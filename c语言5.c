#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,i=1,b;
	a=random(100);
	for (;i<=10;i++);
	{
		scanf("%d",&b);
		if (a==b) printf("恭喜");
	}
	if (i==11) printf("失败");
	return 0;
}
	
		
		
		
	