#include <stdio.h>
int main(void)
{
	printf("请输入该生的考试成绩\n");
	float grade;
	scanf("%f",&grade);
	if (grade>=90)
	{
		putchar('A');
	}
	else if (grade>=80)
	{
		putchar('B');
	}
	else if (grade>=70)
	{
		putchar('C');
	}
	else if (grade>=60)
	{
		putchar('D');
	}
	else 
	{
		putchar('E');
	}
	return 0;
}
		