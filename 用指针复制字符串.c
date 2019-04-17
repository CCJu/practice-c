#include <stdio.h>
void copy(char *from,char *to)
{
	for (;(*from)!='\0';from++,to++)
	    *to=*from;
	*to='\0';
}
int main()
{
	char *a,*b;
	a="I am a student.";
	b="You are a student.";
	printf("%s\n%s\n",a,b);
	copy(a,b);
	printf("%s\n%s\n",a,b);
	return 0;
}
	