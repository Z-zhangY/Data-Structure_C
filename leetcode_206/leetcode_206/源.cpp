#include<stdio.h>
#include<stdlib.h>


//方法一
//struct ListNode* reverseList(struct ListNode* head) 
//{
//	//判断是否为空链表
//	if (head ==	NULL)
//		return NULL;
//
//	struct ListNode* n1 = NULL;
//	struct ListNode* n2 = head;
//	struct ListNode* n3 = head->next;
//	while (head)
//	{
//		//核心逻辑，反转链表方向
//		n1 = n2->next;
//
//		n1 = n2;
//		n2 = n3;
//
//		if (n3)
//			n3 = n3->next;
//		
//	}
//	return n1;
//}

//方法二

struct ListNode
{
	int val;
	struct ListNode* next;
};


struct ListNode* reverseList(struct ListNode* head)
{

	struct ListNode* cur = head;
	struct ListNode* newnode = NULL;
	struct ListNode* next = NULL;

	while (cur)
	{

		next = cur->next;
		cur->next = newnode;
		newnode = cur;
		cur = next;
	}
	return newnode;
}

int main()
{
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n1->val = 1;
	n2->val = 2;
	n3->val = 3;
	n4->val = 4;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	reverseList(n1);
	return 0;
}