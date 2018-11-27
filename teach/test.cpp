#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<Windows.h>

#define STACKINCREMENT 10
#define STACK_INIT_SIZE 100

#define ok 1
#define error 0
#define overflow -1;

typedef char selemtype;
typedef int status;

typedef struct BiTNode
{
	selemtype data;
	struct BiTNode *lchild, *rchild;
}	BiTNode,	 *BiTree;

typedef struct stack
{
	BiTree _array[STACKINCREMENT];
	int _size;
}	stack;

void initstack(stack* s)
{
	assert(s);
	s->_size = 0;
}

void push(stack* s, BiTree e)
{
	assert(s);
	if (s->_size == STACKINCREMENT)
		return;
	s->_array[s->_size++] = e;
}

BiTree top(stack* s)
{
	assert(s);
	return s->_array[s->_size - 1];
}

status emptystack(stack* s)
{
	assert(s);
	return 0 == s->_size;
}

void pop(stack* s)
{
	assert(s);
	if (emptystack(s))
	{
		return;
	}
	s->_size--;
}

status CreateBiTree(BiTree &T)
{
	char ch;
	ch = getchar();
	if (ch == '@')
	{
		T = NULL;
	}
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		if (!T)
		{
			return overflow;
		}
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return ok;
}

status InOrderTraverse(BiTree T)
{
	stack s;  
	initstack(&s); 
	BiTree p; 
	p = T;
	while (p || !emptystack(&s))
	{
		while (p)
		{
			push(&s, p);
			p = p->lchild;
		}
		BiTree top1 = top(&s);
		printf("%c", top1->data);
		pop(&s);
		p = top1->rchild;
	}
	printf("\n");
	return ok;
}

void Test(void)
{
	stack s;
	BiTree T;
	initstack(&s);
	printf("请按先序输入二叉树的元素空元素用@代替\n");
	CreateBiTree(T);
	printf("二叉树创建成功\n");
	printf("现将以非递归算法实现二叉树的遍历并输出元素\n");
	InOrderTraverse(T);
}

int main()
{
	Test();
	system("pause");
	return 0;
}
