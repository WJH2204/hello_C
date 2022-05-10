#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		print_meau();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("You have successfully exited the game\n");
			break;
		default:
			printf("Input errors, please re-enter.\n");
			break;
		}
	} while (input);


	return 0;
}

void game()
{
	char ret = ' ';
	//creat board
	char board[ROW][COL] = { 0 };
	//initialize board
	init_board(board, ROW, COL);
	//print board
	print_board(board, ROW, COL);
	while (1)
	{
		//player chess
		play_chess(board, ROW, COL);
		//display chess
		print_board(board, ROW, COL);
		//judging win or lose
		ret = win_lose(board, ROW, COL);
		if (ret == '*')
		{
			printf("you win\n");
			break;
		}
		if (ret == 'q')
		{
			printf("you don't win\n");
			break;
		}
		//computer chess
		printf("the computer has played the chess\n");
		compu_chess(board, ROW, COL);
		//display chess
		print_board(board, ROW, COL);
		//judging win or lose
		ret = win_lose(board, ROW, COL);
		if (ret == '#')
		{
			printf("you lose\n");
			break;
		}
		if (ret == 'q')
		{
			printf("you don't win\n");
			break;
		}
	}
}