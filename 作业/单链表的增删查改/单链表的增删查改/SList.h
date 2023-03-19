#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDateType;

typedef struct SListNode
{
	SLTDateType date;
	struct SListNode* next;
} SListNode;

SListNode* BuySListNode(SLTDateType x);

void SListPrint(SListNode* plist);

void SListPushBack(SListNode** pplist, SLTDateType x);

void SListPushFront(SListNode** pplist, SLTDateType x);

void SListPopBack(SListNode** pplist);

void SListPopFront(SListNode** pplist);

SListNode* SListFind(SListNode* plist, SLTDateType x);

void SListInsertAfter(SListNode* pos, SLTDateType x);

void SListEraseAfter(SListNode* pos);

void SListDestroy(SListNode** pplist);
