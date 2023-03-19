#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

void HeapSort(int* a, int n);

void ReadDate(const char* filename, int* a);

void CreateDate(const char* filename, int n);