#include <stdio.h>
int main()
{
	int a,b,c,d,s;
	for (a=1;a<=30;a++)
	{
		for (b=1;b<=30;b++)
		{
			for (c=1;c<=30;c++)
			{
				for (d=1;d<=30;d++)
				{
					s=a*50+b*20+c*10+d*5;
					if (s==500&&a+b+c+d==30) 
					{
						  printf("%d,%d,%d,%d\n",a,b,c,d);
					}
				}
			}
		}
	}
	return 0;
}