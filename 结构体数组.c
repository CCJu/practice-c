#include <stdio.h>
struct person
{
	char name[20];
	int count;
}leader[3]={"li",0,"wang",0,"wei",0};
int main()
{
	int i,j;
	char a[20];
	for (i=1;i<=9;i++)
	{
		scanf("%s",&a);
		for (j=0;j<=2;j++)
		    if(strcmp(a,leader[j].name)==0) 
		        leader[j].count++;
	}
	for (i=0;i<=2;i++)
	    printf("%s:%d\n",leader[i].name,leader[i].count);
	return 0;
}