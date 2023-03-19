
#include "List.h"

void test1()
{

	ListNode* head = ListCreate();

	ListPushBack(head, 1);
	ListPushBack(head, 2);
	ListPushBack(head, 3);
	ListPrint(head);

	ListPushFront(head, 10);
	ListPushFront(head, 20);
	ListPushFront(head, 30);
	ListPrint(head);


	ListPopBack(head);
	ListPrint(head);


	ListPopFront(head);
	ListPrint(head);


	ListDestory(head);


}

int main()
{
	test1();

	return 0;
}