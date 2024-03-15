#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


struct ListNode 
{
	int val;
	struct ListNode* next;
};


int kthToLast(struct ListNode* head, int k)
{
	assert(head);
    struct ListNode* fast = head;
    struct ListNode* slow = head;
	int i = 0;
    while (fast)
    {
		if (i < k)
		{
			for (i = 1; i <= k; i++)
			{
				fast = fast->next;
			}
		}

        fast = fast->next;
        slow = slow->next;
    }
    return slow->val;
}

//struct ListNode* FindKthToTail(struct ListNode* pHead, int k)
//{
//	// write code here
//	struct ListNode* fast = pHead;
//	struct ListNode* slow = pHead;
//	while (k--)
//	{
//		if (!fast)
//		{
//			return NULL;
//		}
//		fast = fast->next;
//	}
//	while (fast)
//	{
//		fast = fast->next;
//		slow = slow->next;
//	}
//	return slow;
//}

struct ListNode* FindKthToTail(struct ListNode* pHead, int k)
{
	// write code here
	struct ListNode* fast = pHead;
	struct ListNode* slow = pHead;
	int i = 0;
	while (fast)
	{
		if (i < k)
		{
			for (i = 1; i <= k; i++)
			{
				if (fast == NULL)
				{
					return NULL;
				}
				fast = fast->next;
			}
		}

		if (fast == NULL)
		{
			return slow;
		}
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

int main()
{
	int k = 0;
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
	n4->next = NULL;
	FindKthToTail(n1, 2);
	return 0;
}