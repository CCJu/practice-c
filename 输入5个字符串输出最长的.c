#include <stdio.h>
#include <string.h>
int main()
{
	int i;
	char str[5][100];
	for (i = 0; i < 5; i++)
	{
		scanf("%s", str[i]);
	}
	int n = 0;
	int length = strlen(str[0]);
	for (i = 1; i < 5; i++)
	{
		if (strlen(str[i]) > length)
		{
			length = strlen(str[i]);
			n = i;
		}
	}
	printf("Longest:str[%d] = %s", n, str[n]);
	return 0;
}