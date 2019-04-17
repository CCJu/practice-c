#include <stdio.h>
int main()
{
	int i,m=0,n=0,q=0;
	char a[100],c,*p;
    for (p=a;(c=getchar())!='\n';p++)
	{
	    *p=c;
		if (*p>='a'&&*p<='z') m++;
		if (*p>='A'&&*p<='Z') m++;
		if (*p==' ') n++;
		if (*p>='0'&&*p<='9') q++;
	}
	printf("英文字符有%d个\n",m);
	printf("空格有%d个\n",n);
	printf("数字有%d个\n",q);
	return 0;
}