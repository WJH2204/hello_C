
#include <stdio.h>
#define ROW 3
#define LINE 3

struct Coord
{
	int x;
	int y;
};

struct Coord ser_key(int arr[][LINE], int key, int row, int line)
{
	int i = 0;
	int j = line - 1;
	struct Coord r = { -1,-1 };
	while (i < row && j >= 0)
	{
		if (arr[i][j] > key)
		{
			j--;
		}
		else if (arr[i][j] < key)
		{
			i++;
		}
		else
		{
			r.x = i;
			r.y = j;
			return r;
		}
	}
	return r;
}

int main()
{
	int arr[ROW][LINE] = { 1,2,3,4,5,6,7,8,9 };
	struct Coord ret = ser_key(arr, 20, ROW, LINE);
	if (ret.x == -1)
	{
		printf("Can't find it.\n");
	}
	else
	{
		printf("Find it, the coordinate is (%d, %d).\n", ret.x, ret.y);
	}
	return 0;
}