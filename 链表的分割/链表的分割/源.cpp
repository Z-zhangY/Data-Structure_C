#include<stdio.h>
#include<stdlib.h>

//·Ö¸îÁ´±í


struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
}; 
class Partition
{
public:
    ListNode* partition(ListNode* pHead, int x)
    {
        // write code here

        struct ListNode* lessHead, * lessTail, * greaterHead, * greaterTail;
        lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));

        greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));

        lessTail->next = NULL;
        greaterTail->next = NULL;
        struct ListNode* PL = pHead;
        while (PL)
        {

            if (x > PL->val)
            {
                lessTail->next = PL;
                lessTail = lessTail->next;
            }
            else
            {
                greaterTail->next = PL;
                greaterTail = greaterTail->next;
            }
            PL = PL->next;
        }
        lessTail->next = greaterHead->next;
        greaterTail->next = NULL;
        struct ListNode* plist = lessHead->next;

        free(lessHead);
        free(greaterHead);
        return plist;

    }

};