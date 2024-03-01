#include"SeqList.h"

//��ӡ
void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d  ", ps->a[i]);
	}
	printf("\n");
}

//��ʼ��
void SeqListInti(SL* ps) //
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

// �����ͷſռ�
void SeqListDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;

}

//�жϿռ�����
void SLCheckCapacity(SL* ps)
{
	//�ж�ʣ��ռ�
	if (ps->size == ps->capacity)
	{
		//����ռ䲻��������
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}
//void panduan(SL* ps)
//{
//
//}

// β��
void SeqListPushBack(SL* ps, SLDataType x)
{
	//SLCheckCapacity(ps); //�������

	//ps->a[ps->size] = x; // �����ݴ洢��������
	//ps->size++;          // �洢��֮���±�++
	
	//�Ż�
	SeqListInsert(ps, ps->size, x);
}

// βɾ
void SeqListPopBack(SL* ps)
{
	//if (ps->size > 0)
	//{
	//	//ps->a[ps->size--] = 0;
	//	ps->size--;
	//}
	assert(ps->size > 0);
	ps->size--;
	//�����������Ϊ�٣�ֱ����ֹ����
}

// ͷ��
void SeqListPushFront(SL* ps, SLDataType x)
{
	//SLCheckCapacity(ps); //�������

	//// �����ݴ�ǰ����һ��һ��Ų��
	////Ų������
	//int end = ps->size - 1; 
	//while (end >= 0)
	//{
	//	ps -> a[end + 1] = ps->a[end];
	//	end--;
	//}
	//ps -> a[0] = x;
	//ps->size++;

	//�Ż�
	SeqListInsert(ps, 0, x);
}

// ͷɾ
void SeqListPopFront(SL* ps)
{
	assert(ps->size > 0);
	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		++begin;
	}
	ps->size--;
}


// ����
int SeqListFind(SL* ps, SLDataType x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i]==x)
		{
			return i;
		}
	}

	return -1; 
}

// ָ���±�λ�ò���
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	// 1
	//if (pos > ps->size || pos < 0)
	//{
	//	printf("pos is inalid\n");
	//	return;
	//}

	// 2
	assert(pos <= ps->size && pos >= 0);

	// ��������
	SLCheckCapacity(ps);
	int end = ps->size;
	while (end >= pos)
	{
		ps->a[end+1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}


// ɾ��ָ��λ��
void SeqListErase(SL* ps, int pos)
{
	assert(pos <= ps->size && pos >= 0);
	int begin = pos + 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;
}
