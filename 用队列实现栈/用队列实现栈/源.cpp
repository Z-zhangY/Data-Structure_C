#include<stdio.h>
#include<stdlib.h>
#include<assert.h>



typedef struct tagListNode {
    int val;
    struct tagListNode* next;
} ListNode;


typedef struct {
    ListNode* top;
} MyStack;


MyStack* myStackCreate() {
    MyStack* stack = malloc(sizeof(MyStack));
    if (stack == NULL) {
        return NULL;
    }
    stack->top = NULL;
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    ListNode* node = malloc(sizeof(ListNode));
    if (node == NULL) {
        return;
    }
    node->val = x;
    node->next = obj->top;
    obj->top = node;
    return;
}

int myStackPop(MyStack* obj) {
    ListNode* tmp = obj->top;
    int val = tmp->val;

    obj->top = tmp->next;
    free(tmp);
    return val;
}

int myStackTop(MyStack* obj) {
    return obj->top->val;
}

//�пգ�������ж�������Ϊ�գ��������������Ϊ��
bool myStackEmpty(MyStack* obj) 
{
    if (obj->top == NULL) {
        return true;
    }
    else {
        return false;
    }
}

void myStackFree(MyStack* obj) {
    ListNode* tmp;
    while (obj->top != NULL) {
        tmp = obj->top;
        obj->top = tmp->next;
        free(tmp);
    }
    free(obj);
}










// ������������
typedef int QDataType;
// ����һ������
typedef struct Queue
{
    QueueNode* head;
    QueueNode* tail;
}Queue;
// �������н��
typedef struct QueueNode
{
    struct QueueNode* next;
    QDataType data;
}QueueNode;
// ������������
typedef struct
{
    Queue q1;
    Queue q2;

} MyStack;

// ��ʼ������
void QueueInit(Queue* pq)
{
    assert(pq);
    pq->head = NULL;
    pq->tail = NULL;
}
//�����п�
bool QueueEmpty(Queue* pq)
{
    assert(pq);
    //���ͷָ��Ϊ�վͱ���
    return pq->head == NULL;
}
// ��������
void QueueDestroy(Queue* pq)
{
    assert(pq);
    QueueNode* cur = pq->head;
    while (cur != NULL)
    {
        QueueNode* next = cur->next;
        free(cur);
        cur = next;
    }
    pq->head = pq->tail = NULL;
}
// ���빦��
void QueuePush(Queue* pq, QDataType x)
{
    assert(pq);
    QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
    newnode->data = x;
    newnode->next = NULL;
    if (pq->head == NULL)
    {
        pq->head = pq->tail = newnode;
    }
    else
    {
        //tailָ��newnode
        //newnode����µ�tail
        pq->tail->next = newnode;
        pq->tail = newnode;
    }
}

// ɾ������
void QueuePop(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    //��ôд��ɾ��֮��tail���ΪҰָ��
    QueueNode* next = pq->head->next;
    free(pq->head);
    pq->head = next;
    if (pq->head == NULL)
    {
        pq->tail = NULL;
    }
}
//�Ҷ��е�ͷ
QDataType QueueFront(Queue* pq)
{
    assert(pq);
    return pq->head->data;
}
//�Ҷ��е�β
QDataType QueueBack(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    return pq->tail->data;
}
//���еĴ�С
int QueueSize(Queue* pq)
{
    assert(pq);
    int n = 0;
    QueueNode* cur = pq->head;
    while (cur)
    {
        ++n;
        cur = cur->next;
    }
    return n;
}

// ��ʼ��
//�����ﴴ���ṹ���ʱ��Ҫע��Ұָ��
MyStack* myStackCreate()
{
    MyStack* st = (MyStack*)malloc(sizeof(MyStack));
    QueueInit(&st->q1);
    QueueInit(&st->q2);
    return st;
}


void myStackPush(MyStack* obj, int x)
{
    //�������1Ϊ�գ�������ݲ������2
    //�������2Ϊ�գ�������ݲ������1
    if (!QueueEmpty(&obj->q1))
    {
        QueuePush(&obj->q1, x);
    }
    else
    {
        QueuePush(&obj->q2, x);
    }
}

int myStackPop(MyStack* obj)
{
    //������������
    //Ĭ�Ͽն���Ϊq1���ǿ�Ϊq2
    Queue* emptyQ = &obj->q1;
    Queue* nonemptyQ = &obj->q2;
    //�������Ĭ����������෴
    if (!QueueEmpty(&obj->q1))
    {
        emptyQ = &obj->q2;
        nonemptyQ = &obj->q1;
    }

    //����һ��whileѭ�����������һ��Ԫ��Ȼ��ɾ��
    while (QueueSize(nonemptyQ) > 1)
    {
        QueuePush(emptyQ, QueueFront(nonemptyQ));
        QueuePop(nonemptyQ);
    }

    //��Ϊ��Ҫ����ɾ����Ԫ�أ�����ɾ��֮ǰ�ȱ���һ��
    //���Ԫ�ص�λ���ڶ�β
    int top = QueueFront(nonemptyQ);
    QueuePop(nonemptyQ);
    return top;
}

//����ջ��Ԫ�أ�ջ��Ԫ��Ҳ���Ƕ�βԪ��
int myStackTop(MyStack* obj)
{
    if (!QueueEmpty(&obj->q1))
    {
        return QueueBack(&obj->q1);
    }
    else
    {
        return QueueBack(&obj->q2);
    }
}

bool myStackEmpty(MyStack* obj)
{
    //�������ж���Ϊ��
    return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj)
{
    //���ͷ��ڴ�֮ǰ����Ҫ�����ٶ���֮ǰ���ٵĿռ�
    QueueDestroy(&obj->q1);
    QueueDestroy(&obj->q2);
    free(obj);

}