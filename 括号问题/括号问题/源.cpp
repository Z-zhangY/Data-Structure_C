#include<stdio.h>
#include<stdlib.h>
#include<assert.h>



typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void StackInti(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	//��ʼ��ʱ��top������0����ζ��ָ��ջ�����ݵ���һ��
	//���������-1����ζ��topָ��ջ������
	ps->capacity = 0;
}



void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}



void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = realloc(ps->a, sizeof(STDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newCapacity;
	}

	ps->a[ps->top] = x;
	ps->top++;
}



void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);

	ps->top--;
}



STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);

	return ps->a[ps->top - 1];
}



bool StackEmpty(ST* ps)
{
	assert(ps);

	if (ps->top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

	//return ps->top == 0;
}
bool isValid(char* s)
{
	ST st;
	StackInti(&st);
	while (*s)
	{
		if ((*s == '(') || (*s == '[') || (*s == '{'))
		{
			StackPush(&st, *s);
			s++;
		}
		else
		{
			//���ջ�ǿյģ�˵��û����֮��ƥ��������ţ�����false
			//���s���������ţ���ôȡ��ջ������������֮��Ƚ�
			if (StackEmpty(&st))
			{
				StackDestroy(&st);
				return false;
			}

			// ȡ��ջ����ֵ
			STDataType top = StackTop(&st);
			StackPop(&st);
			if ((*s == ')' && top != '(')
				|| (*s == ']' && top != '[')
				|| (*s == '}' && top != '{'))
			{
				StackDestroy(&st);
				return false;
			}
			else
			{
				s++;
			}
		}
	}

	//���ջ���ǿգ�˵��ջ�л���������δƥ��
	bool ret = StackEmpty(&st);
	StackDestroy(&st);
	return ret;
}