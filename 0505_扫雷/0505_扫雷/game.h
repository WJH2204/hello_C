#pragma once

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROWS 11
#define COLS 11

#define ROW 9
#define COL 9

#define numines 9

void print_meau();

void game();

void init_arr(char arr[ROWS][COLS], int row, int col, char c);

void print_arr(char arr[ROWS][COLS], int row, int col);

void set_mines(char arr[ROWS][COLS], int row, int col, int num);

void play(char mines[ROWS][COLS], char show[ROWS][COLS], int rows, int cols, int row, int col);

int sum_around(char mines[ROWS][COLS], int x, int y);

void much_show(char mines[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* key);