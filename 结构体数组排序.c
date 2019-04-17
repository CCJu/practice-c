#include <stdio.h>
struct person
{
	long int num;
	char name[20];
	int score;
}leader[5]={1000,"li",78,1001,"wang",99,1002,"wei",67,1003,"sheng",79,1004,"qian",94};
int main()
{
	int i,t,j;
	float max=leader[0].score;
	for (i=0;i<=4;i++)
	{
		for (j=0;j<=4;j++)
		    if(leader[j].score>max)     
		    {
		    	max=leader[j].score;
		    	t=j;
		     }
		printf("%ld %s %d\n",leader[t].num,leader[t].name,leader[t].score);
		leader[t].score=0;
		max=0;
	}
	return 0;
}