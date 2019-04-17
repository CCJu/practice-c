#include <stdio.h>
int main(void)
{
	int x = 5;
	int y = 5;
	int z = 10;
	printf("x是否大于y:%d\n",x>y);
	printf("y是否大于等于x:%d\n",y>=x);
	printf("y是否小于z:%d\n",y<z);
	printf("z是否小于等于x:%d\n",z<=x);
	printf("z是否等于x+y:%d\n",z==x+y);
	return 0;
}