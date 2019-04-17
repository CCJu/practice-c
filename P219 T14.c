#include  <stdio.h>
float b[10];
void ave1(float a[10][5])
{
	int j,k;
	float s=0;
	for (k=0;k<=4;k++)
	{
	    for (j=0;j<=9;j++)
	        s+=a[j][k];
	    printf("第%d课的平均成绩为%.4f\n",k,s/10.0); s=0;
	}
}
void ave2(float a[10][5])
{
	int j,k;
	float s=0;
	for (j=0;j<=9;j++)
	{
	    for (k=0;k<=4;k++)
	       s+=a[j][k]; 
	    b[j]=s/5.0;
	    printf("第%d学生的平均成绩为%.4f\n",j,b[j]); s=0;
	}
}
void max(float a[10][5])
{
	int j,k,m,n;
	float max=0;
	for (j=0;j<=9;j++)
	    for (k=0;k<=4;k++)
	    {
	        if (max<a[j][k]) 
	        {
	        	max=a[j][k];
	        	m=j; n=k;
	        }	 	
	    }
	    printf("最高的分数为第%d个考生的第%d门课\n",m,n);
}
void s(float b[10])	      
{
	int i;
	float s1,s2=0,s;
	for (i=0;i<=9;i++)
	{
		s1=b[i]*b[i];
		s2+=b[i];
    }  
    s=s1/10.0-(s2/10.0)*(s2/10.0);
    printf("%.4f",s);
}
int main()	
{
	printf("请输入10个学生的每门课成绩\n");
	float a[10][5];
	int j,k;
	for (j=0;j<=9;j++)
		for (k=0;k<=4;k++)
		    scanf("%f",&a[j][k]);
	ave1(a);
	ave2(a);
	max(a);
	s(b);
	return 0;
}
	    