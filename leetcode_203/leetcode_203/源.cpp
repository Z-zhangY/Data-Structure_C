#include<stdio.h>
#include<stdlib.h>




// 203. 移除链表元素


 // Definition for singly-linked list.
struct ListNode 
{
      int val;
      struct ListNode *next;
};
 
struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;

    while (cur)
    {
        if (cur->val == val)
        {
            if (cur == head)
            {
                head = cur->next;
                free(cur);
                cur = head;
            }
            else
            {
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}

// 自己创建链表，方便快速调试 OJ 代码

int main()
{
    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n1->val = 7;
    n2->val = 7;
    n3->val = 7;
    n4->val = 7;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;
    //创建节点接收返回
    struct ListNode* head = removeElements(n1, 7);
	return 0;
}

//链表分三种情况
//第一种为空链表，直接返回空
//第二种全为要删除的值，全部为头删情况
//第三种常规情况


