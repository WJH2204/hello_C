#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void print_meau()
{
	printf("**************************\n");
	printf("********  1.play  ********\n");
	printf("********  0.exit  ********\n");
	printf("**************************\n");
	printf("please enter 1 or 0 to play or exit:");
}

void init_board(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}


void print_board(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (j == col - 1)
			{
				printf(" %c ", board[i][j]);
				break;
			}
			printf(" %c |", board[i][j]);
		}
		printf("\n");
		if (i == row - 1)
		{
			for (j = 0; j < col; j++)
			{
				if (j == col - 1)
				{
					break;
				}
				printf("   |");
			}
			printf("\n");
			break;
		}
		for (j = 0; j < col; j++)
		{
			if (j == col - 1)
			{
				printf("___");
				break;
			}
			printf("___|");
		}
		printf("\n");
	}
}

void play_chess(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	while (1)
	{
		printf("please enter the coordinations of where you want to play chess like 1 1:");
		scanf("%d %d", &x, &y);
		if (x <= row && y <= col)
		{
			if (board[x-1][y-1] == ' ')
			{
				board[x-1][y-1] = '*';
				break;
			}
			else
			{
				printf("coordinates have been used\nplease re-enter\n");
			}
		}
		else
		{
			printf("the coordinates you entered exceed the size of the chessboard\nplease re-enter\n\n");
		}
	}
}

void compu_chess(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	//prevent players by row
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col - 1; j++)
		{
			if ((board[i][j] == board[i][j + 1]) && (board[i][j] != ' '))
			{
				if (j + 2 < row)
				{
					if (board[i][j + 2] == ' ')
					{
						board[i][j + 2] = '#';
						goto comchess;
					}
				}
				else if (j - 1 >= 0)
				{
					if (board[i][j - 1] == ' ')
					{
						board[i][j - 1] = '#';
						goto comchess;
					}
				}
			}
		}
	}
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col - 2; j++)
		{
			if ((board[i][j] == board[i][j + 2]) && (board[i][j] != ' '))
			{
				if (board[i][j + 1] == ' ')
				{
					board[i][j + 1] = '#';
					goto comchess;
				}
			}
		}
	}
	//prevent player by col
	for (j = 0; j < col; j++)
	{
		for (i = 0; i < row - 1; i++)
		{
			if ((board[i][j] == board[i + 1][j]) && (board[i][j] != ' '))
			{
				if (i + 2 < row)
				{
					if (board[i + 2][j] == ' ')
					{
						board[i + 2][j] = '#';
						goto comchess;
					}
				}
				else if (i - 1 >= 0)
				{
					if (board[i - 1][j] == ' ')
					{
						board[i - 1][j] = '#';
						goto comchess;
					}
				}
			}
		}
	}
	for (j = 0; j < col; j++)
	{
		for (i = 0; i < row - 2; i++)
		{
			if ((board[i][j] == board[i + 2][j]) && (board[i][j] != ' '))
			{
				if (board[i + 1][j] == ' ')
				{
					board[i + 1][j] = '#';
					goto comchess;
				}
			}
		}
	}
	//prevent player by diagonal(just for threesome)
	for (i = 0; i < row - 1; i++)
	{
		if ((board[i][i] == board[i + 1][i + 1]) && (board[i][i] != ' '))
		{
			if (i + 2 < row)
			{
				if (board[i + 2][i + 2] == ' ')
				{
					board[i + 2][i + 2] = '#';
					goto comchess;
				}
			}
			else if (i - 1 >= 0)
			{
				if (board[i - 1][i - 1] == ' ')
				{
					board[i - 1][i - 1] = '#';
					goto comchess;
				}
			}
		}
	}
	for (i = 0; i < row - 2; i++)
	{
		if ((board[i][i] == board[i + 2][i + 2]) && (board[i][i] != ' '))
		{
			if (board[i + 1][i + 1] == ' ')
			{
				board[i + 1][i + 1] = '#';
				goto comchess;
			}
		}
	}
	for (i = 0; i < row - 1; i++)
	{
		j = col - 1 - i;
		if ((board[i][j] == board[i + 1][j - 1]) && (board[i][j] != ' '))
		{
			if (i + 2 < row)
			{
				if (board[i + 2][col - 1 - (i + 2)] == ' ')
				{
					board[i + 2][col - 1 - (i + 2)] = '#';
					goto comchess;
				}
			}
			else if (i - 1 >= 0)
			{
				if (board[i - 1][col - 1 - (i - 1)] == ' ')
				{
					board[i - 1][col - 1 - (i - 1)] = '#';
					goto comchess;
				}
			}
		}
	}
	for (i = 0; i < row - 2; i++)
	{
		j = col - 1 - i;
		if ((board[i][j] == board[i + 2][j - 2]) && (board[i][j] != ' '))
		{
			if (board[i + 1][col - 1 - (i + 1)] == ' ')
			{
				board[i + 1][col - 1 - (i + 1)] = '#';
				goto comchess;
			}
		}
	}
	while (1)
	{
		i = rand() % 3;
		j = rand() % 3;
		if (board[i][j] == ' ')
		{
			board[i][j] = '#';
			goto comchess;
		}
	}
comchess:
	;
}

char win_lose(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	//win by row
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col - 1; j++)
		{
			if ((board[i][j] == board[i][j + 1]) && (board[i][j] != ' '))
			{
				if (j == 1) //can be optimized
					return board[i][j];
			}
			else
				break;
		}
	}
	//win by col
	for (j = 0; j < col; j++)
	{
		for (i = 0; i < col - 1; i++)
		{
			if ((board[i][j] == board[i + 1][j]) && (board[i][j] != ' '))
			{
				if (i == 1) //can be optimized
					return board[i][j];
			}
			else
				break;
		}
	}
	//win by diagonal(just for threesome)
	for (i = 0, j = 0; i < row - 1 && j < col - 1; i++, j++)
	{
		if ((board[i][j] == board[i + 1][j + 1]) && (board[i][j] != ' '))
		{
			if (i == 1) //can be optimized
				return board[i][j];
		}
		else
			break;
	}
	for (i = 0; i < row - 1; i++)
	{
		j = col - i;
		if ((board[i][j] == board[i + 1][j - 1]) && (board[i][j] != ' '))
		{
			if (i == 1) //can be optimized
				return board[i][j];
		}
		else
			break;
	}
	//determine if there is an empty slot
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 'c';
			}
		}
	}
	return 'q';

}
