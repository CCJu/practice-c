#include <stdio.h>
int main()
{
	int b[4]={0};
	int s=0;
	char i;
	while ((i=getchar())!='\n')
	{
		if (i>='a'&&i<='z') b[0]+=1;
		if (i>='A'&&i<='Z') b[1]+=1;
		if (i>='0'&&i<='9') b[2]+=1;
		if (i==' ') b[3]+=1;
		s++;
	}
	i=s;
	s=b[0]+b[1]+b[2]+b[3];
	printf("英文小写字母有%d\n",b[0]);
	printf("英文大写字母有%d\n",b[1]);
	printf("数字有%d\n",b[2]);
	printf("空格有%d\n",b[3]);
	printf("其他字符有%d\n",i-s);
	return 0;
}