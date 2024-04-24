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

//判空，如果队列顶端数据为空，则代表整个队列为空
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










// 定义数据类型
typedef int QDataType;
// 创建一个队列
typedef struct Queue
{
    QueueNode* head;
    QueueNode* tail;
}Queue;
// 创建队列结点
typedef struct QueueNode
{
    struct QueueNode* next;
    QDataType data;
}QueueNode;
// 定义两个队列
typedef struct
{
    Queue q1;
    Queue q2;

} MyStack;

// 初始化队列
void QueueInit(Queue* pq)
{
    assert(pq);
    pq->head = NULL;
    pq->tail = NULL;
}
//队列判空
bool QueueEmpty(Queue* pq)
{
    assert(pq);
    //如果头指针为空就报错
    return pq->head == NULL;
}
// 队列销毁
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
// 插入功能
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
        //tail指向newnode
        //newnode变成新的tail
        pq->tail->next = newnode;
        pq->tail = newnode;
    }
}

// 删除功能
void QueuePop(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    //这么写在删完之后tail会成为野指针
    QueueNode* next = pq->head->next;
    free(pq->head);
    pq->head = next;
    if (pq->head == NULL)
    {
        pq->tail = NULL;
    }
}
//找队列的头
QDataType QueueFront(Queue* pq)
{
    assert(pq);
    return pq->head->data;
}
//找队列的尾
QDataType QueueBack(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    return pq->tail->data;
}
//队列的大小
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

// 初始化
//在这里创建结构体的时候要注意野指针
MyStack* myStackCreate()
{
    MyStack* st = (MyStack*)malloc(sizeof(MyStack));
    QueueInit(&st->q1);
    QueueInit(&st->q2);
    return st;
}


void myStackPush(MyStack* obj, int x)
{
    //如果队列1为空，则把数据插入队列2
    //如果队列2为空，则把数据插入队列1
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
    //创建两个队列
    //默认空队列为q1，非空为q2
    Queue* emptyQ = &obj->q1;
    Queue* nonemptyQ = &obj->q2;
    //如果不是默认情况，则相反
    if (!QueueEmpty(&obj->q1))
    {
        emptyQ = &obj->q2;
        nonemptyQ = &obj->q1;
    }

    //创建一个while循环，弹出最后一个元素然后删除
    while (QueueSize(nonemptyQ) > 1)
    {
        QueuePush(emptyQ, QueueFront(nonemptyQ));
        QueuePop(nonemptyQ);
    }

    //因为需要返回删除的元素，所以删除之前先保存一下
    //这个元素的位置在队尾
    int top = QueueFront(nonemptyQ);
    QueuePop(nonemptyQ);
    return top;
}

//返回栈顶元素，栈顶元素也就是队尾元素
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
    //两个队列都不为空
    return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj)
{
    //在释放内存之前，需要先销毁队列之前开辟的空间
    QueueDestroy(&obj->q1);
    QueueDestroy(&obj->q2);
    free(obj);

}