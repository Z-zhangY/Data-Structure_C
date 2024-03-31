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
	//初始化时，top给的是0，意味着指向栈顶数据的下一个
	//如果给的是-1，意味着top指向栈顶数据
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
			//如果栈是空的，说明没有与之相匹配的右括号，返回false
			//如果s等于左括号，那么取出栈顶的右括号与之相比较
			if (StackEmpty(&st))
			{
				StackDestroy(&st);
				return false;
			}

			// 取出栈顶的值
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

	//如果栈不是空，说明栈中还有左括号未匹配
	bool ret = StackEmpty(&st);
	StackDestroy(&st);
	return ret;
}