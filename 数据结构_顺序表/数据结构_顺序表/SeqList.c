#include"SeqList.h"

//打印
void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d  ", ps->a[i]);
	}
	printf("\n");
}

//初始化
void SeqListInti(SL* ps) //
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

// 用完释放空间
void SeqListDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;

}

//判断空间容量
void SLCheckCapacity(SL* ps)
{
	//判断剩余空间
	if (ps->size == ps->capacity)
	{
		//如果空间不够就扩容
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

// 尾插
void SeqListPushBack(SL* ps, SLDataType x)
{
	//SLCheckCapacity(ps); //检查增容

	//ps->a[ps->size] = x; // 把数据存储到数组中
	//ps->size++;          // 存储完之后下标++
	
	//优化
	SeqListInsert(ps, ps->size, x);
}

// 尾删
void SeqListPopBack(SL* ps)
{
	//if (ps->size > 0)
	//{
	//	//ps->a[ps->size--] = 0;
	//	ps->size--;
	//}
	assert(ps->size > 0);
	ps->size--;
	//断言如果条件为假，直接终止程序
}

// 头插
void SeqListPushFront(SL* ps, SLDataType x)
{
	//SLCheckCapacity(ps); //检查增容

	//// 把数据从前往后一个一个挪动
	////挪动数据
	//int end = ps->size - 1; 
	//while (end >= 0)
	//{
	//	ps -> a[end + 1] = ps->a[end];
	//	end--;
	//}
	//ps -> a[0] = x;
	//ps->size++;

	//优化
	SeqListInsert(ps, 0, x);
}

// 头删
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


// 查找
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

// 指定下标位置插入
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

	// 考虑扩容
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


// 删除指定位置
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
