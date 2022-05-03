#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//函数声明
void meau();
void game();

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		meau();//打印菜单
		printf("请选择“1或0”以进行游戏或退出：\n");
		scanf("%d", &input);
		//对玩家的选择进行判断
		switch (input)
		{
		case 1:
			game();//进行游戏
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入有误，请重新输入。\n");
			break;
		}
	} while (input);
	return 0;
}

void meau()
{
	printf("*************************\n");
	printf("******** 1. Play ********\n");
	printf("******** 0. Exit ********\n");
	printf("*************************\n");
}

void game()
{
	int key = rand() % 100 + 1;
	//printf("%d\n", key);
	printf("游戏开始，请进行猜测：");
	int n = 0;
	while (1)
	{
		scanf("%d", &n);
		if (n > key)
		{
			printf("大了，请重新猜测：");
		}
		else if (n < key)
		{
			printf("小了，请重新猜测：");
		}
		else
		{
			printf("猜对了\n");
			break;
		}
	}
}