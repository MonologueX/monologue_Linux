#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define ok 1
#define error 0
#define overflow -1;
typedef char selemtype;
typedef int status;
typedef struct BiTNode{
	selemtype data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
typedef struct{
	BiTree *base;
	BiTree *top;
	int stacksize;
}sqstack;
status initstack(sqstack &s){
	s.base = (BiTree*)malloc(STACK_INIT_SIZE*sizeof(BiTree));
	if (!s.base)return error;
	s.top = s.base;
	s.stacksize = STACK_INIT_SIZE;
	return ok;
}
status push(sqstack &s, BiTree e){

	if (s.top - s.base >= s.stacksize){
		printf("\n栈已满需重新分配地址\n");
		s.base = (BiTree*)realloc(s.base, (s.stacksize + STACKINCREMENT)*sizeof(BiTree));
		if (!s.base)return 0;//内存分配失败 
		s.top = s.base + s.stacksize;
		s.stacksize += STACKINCREMENT;
	}

	s.top = s.top++;
	*s.top = e;
	printf("进栈成功\n");
	return ok;
}
status pop(sqstack &s, BiTree e){

	if (s.base == s.top)return error;
	e = *(--s.top);
	printf("\n出栈成功\n");
}
status emptystack(sqstack &s){
	if (s.base == s.top) return ok;
	else return error;
}
status CreateBiTree(BiTree &T){

	char ch;
	ch = getchar();
	if (ch == '@')T = NULL;
	else{
		T = (BiTree)malloc(sizeof(BiTNode));
		if (!T) return overflow;
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
		return ok;
	}
}
status print(selemtype e){
	printf("%c", e);
	return ok;
}
status InOrderTraverse(BiTree T, status(*visit)(selemtype e))
{
	sqstack s;  BiTree p;
	initstack(s);  p = T;
	while (p || !emptystack(s)){

		if (p){
			push(s, p);
			p = p->lchild;
		}
		else{
			p = p->rchild;
			pop(s, p);
		}
	}
	return ok;
}

int main()
{
	sqstack s;
	BiTree T;
	initstack(s);
	printf("请按先序输入二叉树的元素空元素用@代替\n");
	CreateBiTree(T);
	printf("二叉树创建成功\n");
	printf("现将以非递归算法实现二叉树的遍历并输出元素\n");
	InOrderTraverse(T, print);
}

