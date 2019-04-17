#include <stdio.h>
int main()
{
	char a[11];
	void rank(char a[11]);
	gets(a);
	rank(a);
	return 0;
}
void rank(char a[11])
{
	int i,m,n;
	char b[10]={0},max='0';
	for (m=0;m<=9;m++)
	{
        for (i=0;i<=9;i++)
		   if (max<=a[i]) {max=a[i]; n=i;}
	    b[m]=max;
	    a[n]='0';
	    max='0';
	}
	puts(b);
}
	    
	