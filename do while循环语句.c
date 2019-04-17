#include <stdio.h>
int main(void)
{
	int number = 200;
	int year = 2014;
	do
	{
		year = year + 1;
		number *=1.2;
	}while (number<1000);
	printf("到%d年人口超过1000",year);
	return 0;
}