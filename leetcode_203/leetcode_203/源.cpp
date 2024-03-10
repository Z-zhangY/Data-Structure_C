#include<stdio.h>
#include<stdlib.h>




// 203. �Ƴ�����Ԫ��


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

// �Լ���������������ٵ��� OJ ����

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
    //�����ڵ���շ���
    struct ListNode* head = removeElements(n1, 7);
	return 0;
}

//������������
//��һ��Ϊ������ֱ�ӷ��ؿ�
//�ڶ���ȫΪҪɾ����ֵ��ȫ��Ϊͷɾ���
//�����ֳ������


