#include "SList.h"


void test1(SListNode* plist)
{
	/*SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);*/

	//SListPrint(plist);

	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 5);

	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);
}

void test2(SListNode* plist)
{
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);

	SListPrint(plist);

	SListInsertAfter(plist, 100);
	SListInsertAfter(plist, 200);
	SListInsertAfter(plist, 300);
	SListInsertAfter(plist, 400);

	SListPrint(plist);

	SListEraseAfter(SListFind(plist, 2));
	SListEraseAfter(SListFind(plist, 100));
	SListEraseAfter(SListFind(plist, 400));
	SListPrint(plist);

	SListDestroy(&plist);



	//SListPopFront(&plist);
	//SListPrint(plist);

	//SListPopFront(&plist);
	//SListPrint(plist);

	//SListPopFront(&plist);
	//SListPrint(plist);

	//SListPopFront(&plist);
	//SListPrint(plist);

	//SListPopFront(&plist);
	//SListPrint(plist);

	//SListPopFront(&plist);
	//SListPrint(plist);



}



int main()
{
	SListNode* plist = NULL;
	
	test2(plist);

	return 0;
}