#define _CRT_SECURE_NO_WARNINGS 1
/*
Description: Compute the average weight for a population of elephant seals
			 read into an array
Author: Wang Jinhai
Date: 2022.05.02
*/
#include <stdio.h>

int main()
{
	int date[1000] = { 0 };
	//Reda date from txt.file
	FILE* fpread = fopen("elephant_seal_data.txt", "r");
	if (fpread == NULL)
	{
		printf("fail to open the file!\n");
		return 0;
	}
	for (int i = 0; i < 1000; i++)
	{
		fscanf(fpread, "%d ", &date[i]);
	}
	//the sum of weight
	double sum = 0.0;
	for (int i = 0; i < 1000; i++)
	{
		sum += date[i];
	}
	//the average of weight
	printf("Average weight = %.2lf", sum / 1000);
	return 0;
}