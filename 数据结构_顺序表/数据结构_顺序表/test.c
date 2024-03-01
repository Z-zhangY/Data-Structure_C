#include"SeqList.h"


// ��һ��β��ӿں���ʵ��
void TestSeqList1()
{
	SL(s1);
	SeqListInti(&s1);  //��ʼ��
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);


	SeqListPopBack(&s1);
	SeqListPopBack(&s1); 
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	//SeqListPopBack(&s1);
	//SeqListPopBack(&s1);
	SeqListPrint(&s1);


	SeqListPushBack(&s1, 10);
	SeqListPushBack(&s1, 20);
	SeqListPrint(&s1);


	SeqListDestroy(&s1);

	
}
void TestSeqList2()
{
	SL(s1);
	SeqListInti(&s1);  //��ʼ��
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);


	SeqListPushFront(&s1, 10);
	SeqListPushFront(&s1, 20);
	SeqListPushFront(&s1, 30);
	SeqListPushFront(&s1, 40);
	SeqListPushFront(&s1, 50);
	SeqListPushFront(&s1, 60);  //��������������Խ��
	SeqListPushFront(&s1, 70);
	SeqListPrint(&s1);


	SeqListPopFront(&s1);
	SeqListPopFront(&s1);
	SeqListPrint(&s1);


	SeqListDestroy(&s1);
}


void TestSeqList3()
{
	SL(s1);
	SeqListInti(&s1);  //��ʼ��
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);

	SeqListInsert(&s1, 3, 50);
	SeqListInsert(&s1, 2, 10);

	SeqListPrint(&s1);

	int pos = SeqListFind(&s1, 4);
	if (pos != -1)
	{
		SeqListInsert(&s1, pos, 21);
	}
	SeqListInsert(&s1, 0, -1);
	SeqListInsert(&s1, 8, 80);
	SeqListPrint(&s1);

	SeqListDestroy(&s1);
}


void TestSeqList4()
{
	SL(s1);
	SeqListInti(&s1);  //��ʼ��
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);

	SeqListPushFront(&s1, 10);
	SeqListPushFront(&s1, 20);
	SeqListPushFront(&s1, 30);
	SeqListPushFront(&s1, 40);
	SeqListPushFront(&s1, 50);
	SeqListPrint(&s1);

}

void TestSeqList5()
{
	SL(s1);
	SeqListInti(&s1);  //��ʼ��
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPrint(&s1);
	SeqListErase(&s1, 1);
	SeqListPrint(&s1);
}


// дһ��ͨѶ¼�Ĳ˵�
void Menu()
{
	printf("��ѡ�����\n");
	printf("***********************\n");
	printf("****1.ͷ��  2.ͷɾ*****\n");
	printf("****3.β��  4.βɾ*****\n");
	printf("****5.��ӡ  -1.�˳�****\n");
	printf("***********************\n");

}

void Menutest()
{
	SL s1;
	SeqListInti(&s1);
	int input = 0;
	int x = 0;
	while (input != -1)
	{
		Menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("������Ҫͷ������ݣ��� -1 �˳���");
			scanf("%d", &x);
			while (x != -1)
			{
				SeqListPushFront(&s1, x);
				scanf("%d", &x);
			}
			break;
		case 2:
				SeqListPopFront(&s1);
			break;
		case 3:
			printf("������Ҫβ������ݣ��� -1 �˳���");
			scanf("%d", &x);
			while (x != -1)
			{
				SeqListPushBack(&s1, x);
				scanf("%d", &x);
			}
			break;
		case 4:
				SeqListPopBack(&s1);
			break;
		case 5:
			SeqListPrint(&s1);
			break;
		case 6:
			while (input = -1)
			{
				break;
			}
		default:
			printf("�޴�ѡ�����������\n");
			break;
		}
	}
	SeqListDestroy(&s1);
}


int main()
{
	//TestSeqList1();
	//TestSeqList2();
	//TestSeqList3();
	//TestSeqList4();
	//TestSeqList5();
	Menutest();

	return 0;
 }


//void TestSeqList3()
//{
//	SL(s1);
//	SeqListInti(&s1);
//	int i = 0;
//	scanf("%d", &i);
//	switch (i)
//	{
//	case 1:
//		SeqListPushFront(&s1, 10);
//		break;
//	case 2:
//		SeqListPopFront(&s1);
//		break;
//	case 3:
//		SeqListPushBack(&s1, 20);
//		break;
//	case 4:
//		SeqListPopBack(&s1);
//	default:
//		printf("ѡ�����������ѡ��\n");
//	}
//}
//int main()
//{
//	menu();
//	SL(s1);
//	SeqListInti(&s1);
//	int i = 0;
//	scanf("%d", &i);
//	switch (i)
//	{
//	case 1:
//		SeqListPushFront(&s1, 10);
//		break;
//	case 2:
//		SeqListPopFront(&s1);
//		break;
//	case 3:
//		SeqListPushBack(&s1, 20);
//		break;
//	case 4:
//		SeqListPopBack(&s1);
//	default:
//		printf("ѡ�����������ѡ��\n");
//	}
//}

