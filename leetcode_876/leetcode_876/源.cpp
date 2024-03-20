

// 876 链表的中间节点
// 快慢指针

struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}