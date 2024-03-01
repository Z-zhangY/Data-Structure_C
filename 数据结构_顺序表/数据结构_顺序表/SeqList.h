#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#pragma once
#define N 1000
typedef int SLDataType;  //˳����д洢��������

//// ��̬˳���
//typedef struct SeqList
//{
//	int arr[N];
//	int size;//��ʾ����洢�˶���Ԫ��
//}SL;
//
//// �ӿں���   �������� C++ STL 
//// ��̬�ص㣺�ռ�����ֹͣ����
//// ȱ�㣺N ��С�˲����ã������������˷�
//
//void SeqListPushBack(SL* ps, SLDataType X);
//void SeqListPopBack(SL* ps);
//void SeqListPushFront(SL* ps, SLDataType X);
//void SeqListPopFront(SL* ps);


// ��̬˳���

typedef struct SeqList
{
	SLDataType* a;	
	int size;//��ʾ����洢�˶���Ԫ��
	int capacity; //�����ʵ������
}SL;



void SeqListPrint(SL* ps);   // ��ӡ

void SLCheckCapacity(SL* ps);
//void panduan(SL*ps);

// �ӿں���   �������� C++ STL 
void SeqListInti(SL* ps);       //��ʼ��
void SeqListDestroy(SL* ps);     //����  
void SeqListPushBack(SL* ps, SLDataType x);	 //β��	
void SeqListPopBack(SL* ps);    // βɾ
void SeqListPushFront(SL* ps, SLDataType x);   //ͷ��
void SeqListPopFront(SL* ps);   // ͷɾ

// ���Ľӿ�
// ��������λ�ã�����ҵ��������±꣬û�ҵ�����-1
int SeqListFind(SL* ps, SLDataType x);
// ָ��λ�õĲ���
void SeqListInsert(SL* ps, int pos, SLDataType x);
// ָ��λ�õ�ɾ��
void SeqListErase(SL* ps, int pos);