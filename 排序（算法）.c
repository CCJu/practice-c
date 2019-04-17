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
	char min=a[0],t;
	for (m=0;m<=9;m++)
	{
        for (i=m;i<=9;i++)
		   if (min>=a[i]) {min=a[i]; n=i;}
		t=a[m];
		a[m]=min;
		a[n]=t;
		if(m+1<=9) min=a[m+1];
	}
	puts(a);
}
	    
	