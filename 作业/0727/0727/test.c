#include "SeqList.h"

void test_SeqListPushBack(struct SeqList* ps)
{
	SeqListPushBack(ps, 1);
	SeqListPushBack(ps, 2);
	SeqListPushBack(ps, 3);
	SeqListPushBack(ps, 4);
}

void test_SeqListPushFront(struct SeqList* ps)
{
	SeqListPushFront(ps, 5);
	SeqListPushFront(ps, 6);
	SeqListPushFront(ps, 7);
	SeqListPushFront(ps, 8);
}

void test_SeqListPopFront(struct SeqList* ps)
{
	SeqListPopFront(ps);
	SeqListPopFront(ps);
}

void test_SeqListPopBack(struct SeqList* ps)
{
	SeqListPopBack(ps);
	SeqListPopBack(ps);
}

void test_SeqListFind(struct SeqList* ps)
{
	printf("%d\n", SeqListFind(ps, 1));
	printf("%d\n", SeqListFind(ps, 6));
}

void test_SeqListInsert(struct SeqList* ps)
{
	int n = 0;
	scanf("%d", &n);
	SeqListInsert(ps, SeqListFind(ps, n), n * 10);
	scanf("%d", &n);
	SeqListInsert(ps, SeqListFind(ps, n), n * 10);

}

void test_SeqListErase(struct SeqList* ps)
{
	SeqListErase(ps, 2);
}


int main()
{
	struct SeqList s1;
	SeqListInit(&s1);

	test_SeqListPushBack(&s1);

	test_SeqListPushFront(&s1);

	test_SeqListPopFront(&s1);

	test_SeqListPopBack(&s1);

	test_SeqListFind(&s1);

	test_SeqListInsert(&s1);

	test_SeqListErase(&s1);


	SeqListPrint(&s1);
	SeqListDestroy(&s1);


	return 0;
}