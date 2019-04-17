#include <stdio.h>
#include <string.h>
int main()
{
	char a[40],b[20];
	int n,m,i;
    gets(a);
    gets(b);
	n=strlen(a);
	m=strlen(b);
	for (i=0;i<=m-1;i++)
	{
		a[n]=b[i];
		n++;
	}
	puts(a);
    return 0;
}