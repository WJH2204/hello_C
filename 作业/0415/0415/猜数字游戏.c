#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//��������
void meau();
void game();

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		meau();//��ӡ�˵�
		printf("��ѡ��1��0���Խ�����Ϸ���˳���\n");
		scanf("%d", &input);
		//����ҵ�ѡ������ж�
		switch (input)
		{
		case 1:
			game();//������Ϸ
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������롣\n");
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
	printf("��Ϸ��ʼ������в²⣺");
	int n = 0;
	while (1)
	{
		scanf("%d", &n);
		if (n > key)
		{
			printf("���ˣ������²²⣺");
		}
		else if (n < key)
		{
			printf("С�ˣ������²²⣺");
		}
		else
		{
			printf("�¶���\n");
			break;
		}
	}
}