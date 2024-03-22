#include<stdio.h>
#include<math.h>




struct ListNode 
{
    int val;
    struct ListNode* next;
    
};

//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) 
//{
//    struct ListNode* PlA = headA;
//    struct ListNode* PlB = headB;
//
//    //������㲻���ʱ����ѭ��
//    while (PlA != PlB)
//    {
//
//        //����
//        PlA = PlA->next;
//        PlB = PlB->next;
//
//        //�ߵ����������ڿյ�ʱ��֤��û�н���
//        if ((PlA == NULL) && (PlB == NULL))
//        {
//            return NULL;
//        }
//        //��һ���ߵ���ʱ������һ��
//        if (PlA == NULL)
//        {
//            PlA = headB;
//        }
//        if (PlB == NULL)
//        {
//            PlB = headA;
//        }
//    }
//    return PlA;
//}



struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    struct ListNode* LA = headA;
    struct ListNode* LB = headB;
    int len1 = 1;
    while (LA)
    {
        len1++;;
        LA = LA->next;
    }
    int len2 = 1;
    while (LB)
    {
        len2++;
        LA = LA->next;
    }

    int gap = abs(len1 - len2);
       
    struct ListNode* longlist = LA;
    struct ListNode* shortlist = LB;

    if (len1 < len2)
    {
        longlist = LB;
        shortlist = LA;
    }

    while (gap--)
    {
        longlist = longlist->next;
    }

    if (longlist != shortlist)
    {
        longlist = longlist->next;
        shortlist = shortlist->next;
    }
    return longlist;
}