#include"stack.h"
#include"Queue.h"

void test1()
{
	ST st;
	StackInti(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);


	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);

	StackDestroy(&st);
}


void test2()
{
	ST st;
	StackInti(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}

	StackDestroy(&st);
}



//void Queuetest1()
//{
//	Queue q;
//	QueueInit(&q);
//	QueuePush(&q, 1);
//	QueuePush(&q, 2);
//	QueuePush(&q, 3);
//	QueuePush(&q, 4);
//	QueuePush(&q, 5);
//
//	QueuePop(&q);
//	QueuePop(&q);
//	QueuePop(&q);
//	QueuePop(&q);
//	QueuePop(&q);
//	QueuePop(&q);
//
//
//
//	printf("%d\n", QueueBack(&q));
//	//QueuePop(&q);
//	//QueuePop(&q);
//
//	QueueDestroy(&q);
//
//}


void Queuetest2()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	while (!QueueEmpty(&q))
	{
		QDataType front = QueueFront(&q);
		printf("%d ",front);
		QueuePop(&q);
	}
	printf("\n");

}



int main()
{
	//test1();
	//test2();

	//Queuetest1();
	Queuetest2();

	return 0;
}