#include <stdio.h>
int main()
{
	int i,n;
	float a[10],s=0;
	for (i=0;i<=9;i++)
	{
		scanf("%f",&a[i]);
		s+=a[i];
	}
	printf("平均成绩为%.3f\n",s/10);
	for (i=0,n=0;i<=9;i++)
		if (a[i]>(s/10)) n++;
	printf("%d",n);
	return 0;
}