#include"List.h"


LTNode* ListInti()
{
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	phead->next = phead;
	phead->prev = phead;
	return phead;
} 




//��ӡ
void ListPrint(LTNode* phead)
{
	assert(phead);

	LTNode* cur = NULL;
	cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

// �����ͷ�Ļ���Ϊ����ָ���ָ���������Բ���Ҫ������ָ��
// 
void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* tail = phead->prev;
	// ͷ����ǰһ������β���
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = x;

	// phead              tail    newnode 
	tail->next = newnode;
	// �����½ڵ�
	newnode->prev = tail;
	phead->prev = newnode;
	newnode->next = phead;
	
	//���ò���ӿ�
	//ListInsert(phead->prev, x);

}


void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead != phead->next);
	// ��ֹɾ���ڱ�λ 

	LTNode* tail = phead->prev;
	LTNode* cur = tail->prev;
	cur->next = phead;
	phead->prev = cur;
	free(tail);
}


void ListPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = x;

	LTNode* cur = phead->next;
	newnode->next = cur;
	cur->prev = newnode;
	newnode->prev = phead;
	phead->next = newnode;

	//���ò���ӿ�
	//ListInsert(phead->next, x);
}

void ListPopFront(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	// �˴����Զඨ��һ������
	phead->next = cur->next;
	cur->next->prev = phead;
	free(cur);
}



LTNode* ListFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}


void ListInsert(LTNode*pos,LTDataType x)
{
	assert(pos);
	LTNode* posPrev = NULL;
	posPrev = pos->prev;
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = x;

	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;
}


void ListErase(LTNode* pos)
{
	assert(pos);
	
	LTNode* pre1 = pos->prev;
	LTNode* next = pos->next;
	pre1->next = next;
	next->prev = pre1;
	free(pos);

}


void ListDestroy(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = cur->next;
	}
	free(phead);
	phead = NULL;
}