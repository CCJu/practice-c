#include <stdio.h>
int main(void)
{
	int score = 7200;
	if(score<1000)
	{
		printf("该玩家为普通玩家");
	}
	else if (score>1000 && score<5000)
	{
		printf("该玩家为青铜玩家");
	}
	else if (score>5000 && score<7000)
	{
		printf("该玩家为白银玩家");
	}
	else if (score>7000 && score<10000)
	{
		printf("该玩家为黄金玩家");
	}
	else if (score>10000)
	{
		printf("该玩家为钻石玩家");
	}
	return 0;
}