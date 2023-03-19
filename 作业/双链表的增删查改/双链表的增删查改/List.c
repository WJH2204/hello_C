
#include "List.h"

ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));

	if (head == NULL)
	{
		perror("ListCreate");
		exit(-1);
	}

	head->prev = head;
	head->next = head;
	head->val = 0;

	return head;
}

void ListDestory(ListNode* phead)
{
	assert(phead);
	
	ListNode* cur = phead->next;

	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);

		cur = next;
	}

	free(phead);
}

void ListPrint(ListNode* phead)
{
	assert(phead);

	ListNode* cur = phead->next;

	printf("phead<->");

	while (cur != phead)
	{
		printf("%d<->", cur->val);
		cur = cur->next;
	}
	printf("\n");
}


ListNode* ListFind(ListNode* phead, LTDateType x)
{
	assert(phead);

	ListNode* cur = phead->next;

	while (cur != phead)
	{
		if (cur->val == x)
		{
			return cur;
		}

		cur = cur->next;
	}

	return NULL;
}

ListNode* BuyNewNode(LTDateType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL)
	{
		perror("BuyNewNode");
		exit(-1);
	}

	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->val = x;

	return newnode;
}

void ListInsert(ListNode* pos, LTDateType x)
{
	assert(pos);

	ListNode* prev = pos->prev;
	ListNode* newnode = BuyNewNode(x);

	prev->next = newnode;
	newnode->prev = prev;

	newnode->next = pos;
	pos->prev = newnode;

}

void ListPushBack(ListNode* phead, LTDateType x)
{
	assert(phead);

	ListInsert(phead, x);
}

void ListPushFront(ListNode* phead, LTDateType x)
{
	assert(phead);

	ListInsert(phead->next, x);
}

void ListErase(ListNode* pos)
{
	assert(pos);

	ListNode* prev = pos->prev;
	ListNode* next = pos->next;

	prev->next = next;
	next->prev = prev;

	free(pos);
}

bool ListEmpty(ListNode* phead)
{
	assert(phead);
	return phead == phead->next;
}

void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(!ListEmpty(phead));

	ListErase(phead->prev);

}

void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(!ListEmpty(phead));

	ListErase(phead->next);

}