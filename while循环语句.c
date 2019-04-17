#include <stdio.h>
int main(void)
{
	int i = 0;
	int s = 0;
	while (i<100)
	{
		i = i + 1;
		s = s + i;
	}
	printf("1到100的和为:%d\n",s);
	return 0;
}