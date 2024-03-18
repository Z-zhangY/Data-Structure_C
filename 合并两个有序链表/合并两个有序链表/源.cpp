#include<stdio.h>
#include<stdlib.h>



struct ListNode 
{
    int val;
    struct ListNode* next;
    
};

//方法一
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode* l1 = list1;
    struct ListNode* l2 = list2;

    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            if (head == NULL)
            {
                head = tail = l1;
            }
            else
            {
                tail->next = l1;
                tail = tail->next;
            }
            l1 = l1->next;
        }
        else
        {
            if (head == NULL)
            {
                head = tail = l2;
            }
            else
            {
                tail->next = l2;
                tail = tail->next;
            }
            l2 = l2->next;
        }
    }
    if (l1)
    {
        tail->next = l1;
    }
    if (l2)
    {
        tail->next = l2;
    }
    return head;
}

//方法二
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode* l1 = list1;
    struct ListNode* l2 = list2;

    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;


    if (l1->val < l2->val)
    {
        if (head == NULL)
        {
            head = tail = l1;
            l1 = l1->next;
        }
    }
    else
    {
        head = tail = l2;
        l2 = l2->next;
    }

    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            tail->next = l1;
            tail = tail->next;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            tail = tail->next;
            l2 = l2->next;
        }
    }
    if (l1)
    {
        tail->next = l1;
    }
    if (l2)
    {
        tail->next = l2;
    }
    return head;
}


//方法三 哨兵位
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode* l1 = list1;
    struct ListNode* l2 = list2;

    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    
    head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));


    while (l1 && l2)
    {
        if (l1->val < l2->val)
        { 
            tail->next = l1;
            tail = tail->next;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            tail = tail->next;
            l2 = l2->next;
        }
    }
    if (l1)
    {
        tail->next = l1;
    }
    if (l2)
    {
        tail->next = l2;
    }
    struct ListNode* list = head->next ;
    free(head);

    return list;
}


int main()
{
    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n1->val = 1;
    n2->val = 2;
    n3->val = 4;
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n4->val = 1;
    n5->val = 3;
    n6->val = 4;
    n4->next = n5;
    n5->next = n6;
    n6->next = NULL;
   
    mergeTwoLists(n1, n4);
    return 0;
}