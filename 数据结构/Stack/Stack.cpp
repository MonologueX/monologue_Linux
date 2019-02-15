#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "Stack.h"
#include <iostream>
using namespace std;
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef char DataType;

typedef struct ListNode
{
    DataType *_data;
    struct ListNode *_next;
}ListNode;

// 初始化
void ListNodeInit(ListNode **ppFirst)
{
    assert(ppFirst != NULL);
    *ppFirst = NULL;
}

// 尾部插入
void ListNodePushBack(ListNode **ppFirst, DataType *data)
{
    assert(ppFirst != NULL);
    ListNode *NewNode = (ListNode *)malloc(sizeof(ListNode));
    assert(NewNode);
    NewNode->_data = data;
    NewNode->_next = NULL;
    if (*ppFirst == NULL)
    {
        *ppFirst = NewNode;
        return;
    }

    ListNode *cur = *ppFirst;
    while (cur->_next != NULL)
    {
        cur = cur->_next;
    }
    cur->_next = NewNode;
}

void Print(ListNode *pFirst)
{
    if (pFirst == NULL)
    {
        return;
    }
    else 
    {
        while(pFirst)
        {
            printf("%s->", pFirst->_data);
            pFirst = pFirst->_next;
        }
        printf("NULL\n");
    }
}

// 头部删除
void ListNodePopFront(ListNode **ppFirst)
{
    assert(ppFirst != NULL);
    assert(*ppFirst != NULL);

    ListNode *del = *ppFirst;
    *ppFirst = del->_next;
    free(del);
    del = NULL;
}

void StackInit(Stack *ps)
{
    assert(ps);
    ps->_top = 0;
}

void StackPush(Stack *ps, DataType data)
{
    assert(ps);
    ps->_array[ps->_top++] = data;
}

void StackPop(Stack *ps)
{
    assert(ps);
    ps->_top--;
}

DataType StackTop(Stack *ps)
{
    assert(ps);
    return ps->_array[ps->_top - 1];
}

int StackSize(Stack *ps)
{
    assert(ps);
    return ps->_top;
}

int StackEmpty(Stack *ps)
{
    assert(ps);
    return 0 == ps->_top;
}

int isoperator(char op)
{
	switch (op)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		return 1;
	default:
		return 0;
	}
}

int priority(char op)
{
	switch (op)
	{
    case '(':
        return 0;
	case '+':
		return 1;
	case '-':
		return 1;
	case '*':
        return 2;
	case '/':
		return 2;
	}
}

//把中缀表达式转换为后缀表达式
void postfix(char pre[], int size)
{
    int j = 0;
	Stack OPTR;   //运算符栈
    ListNode *Result;
    ListNodeInit(&Result);
    StackInit(&OPTR);

    for (int i = 0; i < size; i++)
	{
		if ((pre[i] >= '0' && pre[i] <= '9'))
		{
            char str[10] = "0";
            j = 0;
            str[j++] = pre[i];
            while (pre[i+1] >= '0' && pre[i+1] <= '9')
            {
                str[j++] = pre[i+1];
                i++;
            }
            ListNodePushBack(&Result, str);
            Print(Result);
		}
		else if (pre[i] == '(') 
        {
            printf("遇到(\n");
			StackPush(&OPTR, pre[i]);
        }
		else if (pre[i] == ')') 
		{
            printf("遇到)\n");
            while (1)
			{
                if ('(' == StackTop(&OPTR))
                {
                    printf("左右匹配结束\n");
                    break;
                }
                j = 0;
                char str[10] = "0";
				str[j++] = StackTop(&OPTR);
                ListNodePushBack(&Result, str);
                Print(Result);
				StackPop(&OPTR);
			}
            printf("POP:%c\n", StackTop(&OPTR));
			StackPop(&OPTR);
		}
		else if (isoperator(pre[i]))
		{
            printf("遇见cal:%c\n", pre[i]);
			while (!StackEmpty(&OPTR) && priority(pre[i]) <= priority(StackTop(&OPTR)))
			{
                j = 0;
                char str[3];
				str[j++] = StackTop(&OPTR);
                ListNodePushBack(&Result, str);
                Print(Result);
				StackPop(&OPTR);
			}
			StackPush(&OPTR, pre[i]);
		}
	}
    while (!StackEmpty(&OPTR))
    {
        j = 0;
        char str[3];
		str[j++] = StackTop(&OPTR);
        ListNodePushBack(&Result, str);
        Print(Result);
		StackPop(&OPTR);
    }
    Print(Result);
}

int main()
{
    char exp[] = "12*(3+4)-6+8/2";
    int size = sizeof(exp)/sizeof(exp[0]);
    postfix(exp, size-1);
	return 0;
}
