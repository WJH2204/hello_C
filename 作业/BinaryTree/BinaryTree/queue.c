#include "queue.h"

void QueueInit(Queue* q)
{
	assert(q);

	q->head = NULL;
	q->tail = NULL;
	q->size = 0;
}

void QueuePush(Queue* q, QDateType val)
{
	assert(q);

	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		perror("newnode");
		exit(-1);
	}

	newnode->next = NULL;
	newnode->val = val;

	if (q->tail == NULL)
	{
		q->head = q->tail = newnode;
	}
	else
	{
		q->tail->next = newnode;
		q->tail = q->tail->next;
	}

	q->size++;
}

void QueuePop(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	QueueNode* next = q->head->next;
	free(q->head);

	q->head = next;

	if (q->head == NULL)
	{
		q->tail = NULL;
	}

	q->size--;
}

QDateType QueueHead(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->head->val;
}

QDateType QueueTail(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->tail->val;
}

int QueueSize(Queue* q)
{
	assert(q);

	return q->size;
}

bool QueueEmpty(Queue* q)
{
	assert(q);

	return q->head == NULL;
}

void QueueDestroy(Queue* q)
{
	assert(q);

	QueueNode* cur = q->head;

	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}

	q->head = NULL;
	q->tail = NULL;
	q->size = 0;
}