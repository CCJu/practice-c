#include <stdio.h>
int main()
{
	int m=0,n=0,q=0;
	char c;
    while ((c=getchar())!='\n'){
        if (c>='a'&&c<='z') m++;
	    if (c>='A'&&c<='Z') m++;
		if (c==' ') n++;
		if (c>='0'&&c<='9') q++;}
	printf("英文字符有%d个\n",m);
	printf("空格有%d个\n",n);
	printf("数字有%d个\n",q);
	return 0;
}