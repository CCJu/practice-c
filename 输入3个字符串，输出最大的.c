#include <stdio.h>
#include <string.h>
void max(char *p[3])
{
	int j=0,k=2,max=2;
	for(;j=k;)
	    {
	    	if(strcmp(p[j],p[k])>0) {k--; max=j;}
	    	else j++;
	    }
	printf("%s",p[max]);
}	
int main()
{
	char *str[3],*p=str[0];
	int i;
	for(i=0;i<=2;i++)
	    gets(str[i]);
	max(str);
	return 0;
}
	