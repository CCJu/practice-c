#include <stdio.h>
int main(void)
{
	int i;
	float r,p;
	r = 0.09;
	p = 1+r;
	for (i=2;i<=10;++i)
	{
		p = 1.09*p;
	}
    p-=1;
    p*=100;
	printf("10年后我国的国民生产总值与现在相比增长了%6.3f%%\n",p);
	return 0;
}
	
	    	