#include"List.h"


void test1()
{
	LTNode* Plist = ListInti();

	//Î²²å
	ListPushBack(Plist, 1);
	ListPushBack(Plist, 2);
	ListPushBack(Plist, 3);
	ListPushBack(Plist, 4);
	ListPushBack(Plist, 5);
	ListPrint(Plist);

	//Î²É¾
	ListPopBack(Plist);
	ListPopBack(Plist);
	ListPopBack(Plist);
	ListPopBack(Plist);
	ListPopBack(Plist);
	ListPrint(Plist);

	ListPushFront(Plist, 1);
	ListPushFront(Plist, 2);
	ListPushFront(Plist, 3);
	ListPushFront(Plist, 4);
	ListPushFront(Plist, 5);
	ListPrint(Plist);

}



void test2()
{
	LTNode* Plist = ListInti();


	ListPushFront(Plist, 1);
	ListPushFront(Plist, 2);
	ListPushFront(Plist, 3);
	ListPushFront(Plist, 4);
	ListPushFront(Plist, 5);
	ListPrint(Plist);

	ListPopFront(Plist);
	ListPopFront(Plist);
	ListPopFront(Plist);
	ListPrint(Plist);

}


void test3()
{
	LTNode* Plist = ListInti();
	ListPushFront(Plist, 1);
	ListPushFront(Plist, 2);
	ListPushFront(Plist, 3);
	ListPushFront(Plist, 4);
	ListPushFront(Plist, 5);
	ListPrint(Plist);

	LTNode* pos = ListFind(Plist, 4);
	ListInsert(pos,10);
	ListPrint(Plist);

	if (pos)
	{
		ListErase(pos);
	}
	ListPrint(Plist);
}

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}