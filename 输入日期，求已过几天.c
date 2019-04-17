#include <stdio.h>
int main(void)
{
	int year,month,day;
	printf("请输入日期.例如20121207\n");
	scanf("%4d%2d%2d",&year,&month,&day);
	if ((year%4==0&&year%100==0)||(year%400==0))
	{
		switch (month)
		{
			case 1:month=0; break;
			case 2:month=31; break;
			case 3:month=31+29; break;
			case 4:month=31*2+29; break;
			case 5:month=31*2+29+30; break;
			case 6:month=31*3+30+29; break;
			case 7:month=31*3+30*2+29; break;
			case 8:month=31*4+30*2+29; break;
			case 9:month=31*5+30*2+29; break;
			case 10:month=31*5+30*3+29; break;
			case 11:month=31*6+30*3+29; break;
			case 12:month=31*6+30*4+29; break;
			default : printf("输入错误");
		}
		printf("共过了%d天",month+day);
	}
	else
	{
		switch (month)
		{
			case 1:month=0; break;
			case 2:month=31; break;
			case 3:month=31+28; break;
			case 4:month=31*2+28; break;
			case 5:month=31*2+28+30; break;
			case 6:month=31*3+30+28; break;
			case 7:month=31*3+30*2+28; break;
			case 8:month=31*4+30*2+28; break;
			case 9:month=31*5+30*2+28; break;
			case 10:month=31*5+30*3+28; break;
			case 11:month=31*6+30*3+28; break;
			case 12:month=31*6+30*4+28; break;
			default : printf("输入错误");
		}
		printf("共过了%d天",month+day);
	}
	return 0;
}