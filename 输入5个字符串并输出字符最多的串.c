#include <stdio.h>
#include <string.h>
int main()
{
	int i,n,m;
	char a[5][20];
	for(i=0;i<=4;i++)
		scanf("%s",a[i]);
	for (n=0;n<=4;n++)
	{
		if (strlen(a[n])>i) 
		{
			i=strlen(a[n]);
			m=n;
		}
		printf("%s\n",a[n]);
	}
	printf( "%s",a[m]);
	
	return 0;
}