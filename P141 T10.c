#include <stdio.h>
int main()
{
	int i=1;
	float s=0,b=1,a=2;
	while (i<=20)
	{
		s=s+a/b;
		a=b+a;
		b++;
		i++;
	}
	printf("%f",s);
	return 0;
}