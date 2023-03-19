#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int HPDatetype;

typedef struct Heap
{
	HPDatetype* a;
	int size;
	int capacity;
}Heap;

void HeapCreate(Heap* ph);

void HeapDestory(Heap* ph);

void HeapPush(Heap* ph, HPDatetype val);

void HeapPop(Heap* ph);

HPDatetype HeapTop(Heap* ph);

int HeapSize(Heap* ph);

int HeapEmpty(Heap* ph);

void PrintTopK(int* a, int n, int k);
