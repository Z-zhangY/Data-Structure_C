#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int LTDataType;





typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;


LTNode* ListInti();

void ListPrint(LTNode* phead);

void ListPushBack(LTNode* phead, LTDataType x);

void ListPopBack(LTNode* phead);

void ListPushFront(LTNode* phead,LTDataType x);

void ListPopFront(LTNode* phead);

LTNode* ListFind(LTNode* phead,LTDataType x);

void ListInsert(LTNode* phead, int pos);

void ListErase(LTNode* phead);

void ListDestroy(LTNode* phead);

