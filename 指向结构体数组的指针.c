#include <stdio.h>
struct person
{
	long int num;
	char name[20];
	int score;
}leader[5]={1000,"li",78,1001,"wang",99,1002,"wei",67,1003,"sheng",79,1004,"qian",94};
int main()
{
	struct person *p;
	for (p=leader;p<leader+5;p++)
	    printf("%d %s %d\n",p->num,p->name,p->score);
	return 0;
}