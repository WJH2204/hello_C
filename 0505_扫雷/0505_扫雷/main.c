#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h";

void game()
{
	char mines[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//initialize the array
	init_arr(mines, ROWS, COLS, '0');
	init_arr(show, ROWS, COLS, '*');
	set_mines(mines, ROW, COL, numines);
	print_arr(show, ROW, COL);
	//print_arr(mines, ROW, COL);
	play(mines, show, ROWS, COLS, ROW, COL);
	print_arr(mines, ROW, COL);
}

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
			printf("you have successfully exited the game");
			break;
		default:
			printf("wrong input, please re-enter");
			break;
		}
	} while (input);

	return 0;
}