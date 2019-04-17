#include <stdio.h>
int main()
{
	struct student
	{
		char name[20];
		char sex;
		int age;
	}a={"li lin",'m',18};
	printf("%s\n%c\n%d\n",a.name,a.sex,a.age);
	return 0;
}