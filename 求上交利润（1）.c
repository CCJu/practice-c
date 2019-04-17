#include <stdio.h>
int main(void)
{
	float bonus;
	int a,i;
	printf("请输入利润（对利润取整）\n");
	scanf("%d",&i);
	a=i;
	a/=100000;
	if (i>1000000)
	{
		bonus=100000*(0.1+0.075)+200000*(0.05+0.03)+400000*0.015+(i-1000000)*0.01;
	}
	switch (a)
	{
		case 0:
		case 1:if (i<=100000)
		{
			bonus=i*0.1;
		} else
		{
		 bonus=100000*0.1+(i-100000)*0.075;
		}
		break;
        case 2:if (i>200000)
        {
            bonus=0.175*100000+(i-200000)*0.05;
        }
        else
        {
        	bonus=0.175*100000;
        }
        break;
		case 3:
		case 4:if (i<=400000)
        {
bonus=100000*(0.1+0.075)+(i-200000)*0.05; 
        }
        else
        {
        	bonus=100000*(0.1+0.075)+200000*0.05+(i-400000)*0.03;
        }
        break;
		case 5:
		case 6:if (i<=600000)
		{
			bonus=100000*(0.1+0.075)+200000*0.05+0.03*(i-400000);
		}else 
		{
			bonus=100000*(0.1+0.075)+200000*(0.05+0.03)+(i-600000)*0.015;
		}
		break;
		case 7:
		case 8:
		case 9:
		case 10:if (i<=1000000)
		{
			bonus=100000*(0.1+0.075)+200000*(0.05+0.03)+(i-600000)*0.015;
		}
		break;
    }    
	printf("应发奖金为%.2f",bonus);
	return 0;
}