#pragma once

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 3
#define COL 3


void print_meau();

void game();

void init_board(char board[ROW][COL], int row, int col);

void print_board(char board[ROW][COL], int row, int col);

void play_chess(char board[ROW][COL], int row, int col);

void compu_chess(char board[ROW][COL], int row, int col);

char win_lose(char board[ROW][COL], int row, int col);
