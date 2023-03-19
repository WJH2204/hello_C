#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

void CreateDate(const char* filename, int n);

void HeapTopK(int* a, int k);

void CompareRootWithOther(int* a, int n, int k);

void HeapSort(int* a, int n);