#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void print_meau()
{
	printf("**************************\n");
	printf("********  1.play  ********\n");
	printf("********  0.exit  ********\n");
	printf("**************************\n");
	printf("please input 1 or 0 to play or quit:");
}

void init_arr(char arr[ROWS][COLS], int row, int col, char c)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			arr[i][j] = c;
		}
	}
}


void print_arr(char arr[ROWS][COLS], int row, int col)
{
	int i = 0, j = 0;

	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
	printf("---------- minesweeper game ----------\n");
}

void set_mines(char arr[ROWS][COLS], int row, int col, int num)
{
	int x = 0, y = 0;
	while (num)
	{
		x = (rand() % row) + 1;
		y = (rand() % col) + 1;
		if (arr[x][y] != '1')
		{
			arr[x][y] = '1';
			num--;
		}
	}
}

void play(char mines[ROWS][COLS], char show[ROWS][COLS], int rows, int cols, int row, int col)
{
	int cho = 0;
	int x = 0, y = 0;
	int key = row * col - numines;
	int c;
	int nums = numines;
	do
	{
		printf("\nchoose 1 or 0 to marking or demining:");
		scanf("%d", &cho);
		while ((c = getchar()) != '\n' && c != EOF);
		if (cho == 1)
		{
			while (nums)
			{
				printf("please enter the coordinates you want to mark:");
				scanf("%d %d", &x, &y);
				while ((c = getchar()) != '\n' && c != EOF);
				if ((x >= 1) && (x <= 9) && (y >= 1) && (y <= 9))
				{
					if ((show[x][y] != '@') && (show[x][y] != ' '))
					{
						show[x][y] = '@';
						print_arr(show, ROW, COL);
						if (mines[x][y] == '1')
						{
							nums--;
						}
						if (nums == 0)
						{
							printf("you win\n");
							goto end;
						}
						break;
					}
					else
						printf("input is repeated, please re-enter\n");
						break;
				}
				else
				{
					printf("wrong enter, please re-enter\n");
				}

			}
		}
		else if (cho == 0)
		{
			while (key)
			{
				printf("please enter the coordinates you want to scan:");
				scanf("%d %d", &x, &y);
				if ((x >= 1) && (x <= 9) && (y >= 1) && (y <= 9))
				{
					if (show[x][y] != ' ')
					{
						if (mines[x][y] == '1')
						{
							printf("lose\n");
							print_arr(mines, ROW, COL);
							goto end;
						}
						else
						{
							much_show(mines, show, x, y, &key);
							print_arr(show, ROW, COL);
							break;
						}
					}
					else
					{
						printf("input is repeated, please re-enter");
					}
				}
				else
				{
					printf("wrong enter, please re-enter\n");
				}
			}
			if (key == 0)
			{
				printf("you win\n");
				goto end;
			}
		}
		else
		{
			printf("wrong input, please re-enter");
		}
	} while (1);
end:
	;
}

void much_show(char mines[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* key)
{
	if ((show[x][y] != ' ') && (show[x][y] == '*'))
	{
		
		int sum = sum_around(mines, x, y);
		if (sum != 0)
		{
			show[x][y] = sum + '0';
			(*key)--;
		}
		else
		{
			show[x][y] = ' ';
			(*key)--;
			int i = 0, j = 0;
			for (i = -1; i <= 1; i++)
			{
				for (j = -1; j <= 1; j++)
				{
					if (((x + i) >= 1) && ((x + i) <= 9) && ((y + j) >= 1) && ((y + j) <= 9))
					{
						much_show(mines, show, x + i, y + j, key);
					}
				}
			}
		}
	}

}



int sum_around(char mines[ROWS][COLS], int x, int y)
{
	return (mines[x - 1][y - 1]
		+ mines[x - 1][y]
		+ mines[x - 1][y + 1]
		+ mines[x][y - 1]
		+ mines[x][y + 1]
		+ mines[x + 1][y - 1]
		+ mines[x + 1][y]
		+ mines[x + 1][y + 1] - 8 * '0');
}




