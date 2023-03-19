#pragma once

#include <stdio.h>
#include <assert.h>
#include "stack.h"

typedef int SortDateType;

void InsertSort(int* a, int n);

void Swap(SortDateType* elem1, SortDateType* elem2);

void SelectSort(SortDateType* a, int n);

void PrintArr(SortDateType* a, int n);

void QuickSort(int* a, int left, int right);

void QuickSortNonRecursive(int* a, int left, int right);

void MergeSort(int* a, int n);

void MergeSortNonRecursive(int* a, int n);

void CountSort(int* a, int n);