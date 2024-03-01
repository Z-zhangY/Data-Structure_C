#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#pragma once
#define N 1000
typedef int SLDataType;  //顺序表中存储数据类型

//// 静态顺序表
//typedef struct SeqList
//{
//	int arr[N];
//	int size;//表示数组存储了多少元素
//}SL;
//
//// 接口函数   命名来自 C++ STL 
//// 静态特点：空间满了停止插入
//// 缺点：N 给小了不够用，给大了容易浪费
//
//void SeqListPushBack(SL* ps, SLDataType X);
//void SeqListPopBack(SL* ps);
//void SeqListPushFront(SL* ps, SLDataType X);
//void SeqListPopFront(SL* ps);


// 动态顺序表

typedef struct SeqList
{
	SLDataType* a;	
	int size;//表示数组存储了多少元素
	int capacity; //数组的实际容量
}SL;



void SeqListPrint(SL* ps);   // 打印

void SLCheckCapacity(SL* ps);
//void panduan(SL*ps);

// 接口函数   命名来自 C++ STL 
void SeqListInti(SL* ps);       //初始化
void SeqListDestroy(SL* ps);     //销毁  
void SeqListPushBack(SL* ps, SLDataType x);	 //尾插	
void SeqListPopBack(SL* ps);    // 尾删
void SeqListPushFront(SL* ps, SLDataType x);   //头插
void SeqListPopFront(SL* ps);   // 头删

// 核心接口
// 查找数据位置，如果找到，返回下标，没找到返回-1
int SeqListFind(SL* ps, SLDataType x);
// 指定位置的插入
void SeqListInsert(SL* ps, int pos, SLDataType x);
// 指定位置的删除
void SeqListErase(SL* ps, int pos);