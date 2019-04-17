#include <stdio.h>
void search(float (*p)[4],int n)
{
	int num=0,t;
	for (m=0;m<=n;m++)
	{
	    for (i=0;i<=3;i++)
		    if (*(*(p+m)+i)<60) num++;
		if (num>1) t=m;
		printf("第%d个学生有一门以上不及格\n",t+1);
	}
}
int main()
{
	float a[3][4]={{65,57,70,60},{58,87,90,81},{90,99,100,98}};
	search(a,2);
	return 0;
}

	