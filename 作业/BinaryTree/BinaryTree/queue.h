#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

typedef char BTDateType;
typedef struct BinaryTreeNode {
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDateType val;
} BTNode;

typedef BTNode* QDateType;

typedef struct QueueNode
{
	QDateType val;
	struct QueueNode* next;
} QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
	int size;
} Queue;

void QueueInit(Queue* q);

void QueuePush(Queue* q, QDateType val);

void QueuePop(Queue* q);

QDateType QueueHead(Queue* q);

QDateType QueueTail(Queue* q);

int QueueSize(Queue* q);

bool QueueEmpty(Queue* q);

void QueueDestroy(Queue* q);
