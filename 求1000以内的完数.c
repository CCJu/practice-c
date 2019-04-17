#include <stdio.h>
int main(void)
{
	int m=6,n=1,i=0;
	while (m<=1000)
	{
		while (n<m)
		{
			if (m%n==0) 
			{
				i=i+n;
			}
			n+=1;
		}
		if (i==m) 
		{
			printf("%d\n",m);
		}
		m++;
		i=0;
		n=1;
	}
	return 0;
}
			