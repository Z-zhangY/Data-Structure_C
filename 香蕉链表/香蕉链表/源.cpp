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
//    //两个结点不相等时进入循环
//    while (PlA != PlB)
//    {
//
//        //遍历
//        PlA = PlA->next;
//        PlB = PlB->next;
//
//        //走到两个都等于空的时候证明没有交点
//        if ((PlA == NULL) && (PlB == NULL))
//        {
//            return NULL;
//        }
//        //当一个走到空时遍历另一个
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