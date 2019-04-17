#include <stdio.h>
int main()
{
	int k1,k2,k3;
	k1=k2=k3=1;
	float s=0;
	while (k1<=100)
	{
		s=s+k1;
		k1++;
	}
	while (k2<=50)
	{
		s=s+k2*k2;
		k2++;
	}
	while (k3<=10)
	{
		s=s+1.0/k3;
		k3++;
	}
	printf("此多项式的和为%f\n",s);
	return 0;
}