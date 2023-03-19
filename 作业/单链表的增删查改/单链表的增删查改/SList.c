#include "SList.h"

SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		perror("BuySListNode");
		exit(-1);
	}
	newnode->date = x;
	newnode->next = NULL;
	return newnode;
}

void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;
	while (cur)
	{
		printf("%d->", cur->date);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(pplist);

	if (*pplist == NULL)
	{
		*pplist = BuySListNode(x);

	}
	else
	{
		SListNode* cur = *pplist;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = BuySListNode(x);
	}
}

void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);

	SListNode* newnode = BuySListNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}

void SListPopBack(SListNode** pplist)
{
	assert(pplist);
	if (*pplist == NULL)
	{
		return;
	}

	SListNode* cur = *pplist;

	if (cur->next == NULL)
	{
		free(cur);
		cur = NULL;
		*pplist = NULL;
	}
	else
	{
		while (cur->next->next)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}

void SListPopFront(SListNode** pplist)
{
	assert(pplist);
	if (*pplist == NULL)
	{
		return;
	}
	SListNode* tmp = (* pplist)->next;
	free(*pplist);
	*pplist = tmp;
}

SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	SListNode* cur = plist;
	while (cur)
	{
		if (cur->date == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);

	SListNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	if (pos->next == NULL)
	{
		return;
	}

	SListNode* tmp = pos->next;
	pos->next = pos->next->next;
	free(tmp);
	tmp = NULL;
}

void SListDestroy(SListNode** pplist)
{
	while (*pplist)
	{
		SListNode* next = (*pplist)->next;
		free(*pplist);
		*pplist = next;
	}
	*pplist = NULL;

}