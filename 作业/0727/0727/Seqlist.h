#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <assert.h>

#include <stdlib.h>
typedef int SLDateType;

typedef struct SeqList
{
	SLDateType* a;
	size_t size;
	size_t capacity;
}SeqList;

//void SeqListInit(struct SeqList* ps);
//void SeqListInit(SeqList* ps);
void SeqListInit(SeqList* ps);


void SeqListDestroy(SeqList* ps);

void SeqListPrint(SeqList* ps);

void SeqListPushBack(SeqList* ps, SLDateType x);

void SeqListPushFront(SeqList* ps, SLDateType x);

void SeqListPopFront(SeqList* ps);

void SeqListPopBack(SeqList* ps);

int SeqListFind(SeqList* ps, SLDateType x);

void SeqListInsert(SeqList* ps, size_t pos, SLDateType x);

void SeqListErase(SeqList* ps, size_t pos);


