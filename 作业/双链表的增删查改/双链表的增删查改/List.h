#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int LTDateType;

typedef struct ListNode
{
	LTDateType val;
	struct ListNode* next;
	struct ListNode* prev;
} ListNode;

ListNode* ListCreate();

void ListDestory(ListNode* phead);

void ListPrint(ListNode* phead);

ListNode* ListFind(ListNode* phead, LTDateType x);

void ListInsert(ListNode* pos, LTDateType x);

void ListPushBack(ListNode* phead, LTDateType x);

void ListPushFront(ListNode* phead, LTDateType x);

void ListErase(ListNode* pos);

void ListPopFront(ListNode* phead);

bool ListEmpty(ListNode* phead);
