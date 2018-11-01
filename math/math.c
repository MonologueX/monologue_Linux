#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>

typedef struct node
{
	float coef;    //系数 
	int expn;     //指数 
	struct node *next;
}Lnode, *Linklist;

void Insert(Linklist p, Linklist h)
{
	if (p->coef == 0)
	{
		free(p);
	}
	else
	{
		Linklist q1, q2;
		q1 = h; q2 = h->next;
		while (q2 && p->expn<q2->expn)
		{  
			q1 = q2;
			q2 = q2->next;
		}
		if (q2 && p->expn == q2->expn)
		{   //将指数相同相合并
			q2->coef += p->coef;
			free(p);
			if (!q2->coef)
			{   //系数为0的话释放结点
				q1->next = q2->next;
				free(q2);
			}
		}
		else 
		{   //指数为新时将结点插入
			p->next = q2;
			q1->next = p;
		}
	}
}

Linklist Creat(Linklist head, int n)
{
	Linklist L;
	L = head = (Linklist)malloc(sizeof(Lnode));
	L->next = NULL;
	
	for (int i = 0; i < n; i++)
	{
		Linklist p = (Linklist)malloc(sizeof(Lnode));
		printf("请输入系数：");
		scanf("%f", &p->coef);
		printf("请输入指数：");
		scanf("%d", &p->expn);
		Insert(p, head);
	}
	return head;
}

int compare(Linklist a, Linklist b){
	if (a && b)
	{
		if (!b || a->expn>b->expn) 
			return 1;
		else if (!a || a->expn<b->expn) 
			return -1;
		else return 0;
	}
	else if (!a&&b) 
		return -1;//a多项式已空，但b多项式非空
	else 
		return 1;//b多项式已空，但a多项式非空
}
Linklist Add(Linklist pa, Linklist pb)
{
	Linklist qa = pa->next;
	Linklist qb = pb->next;
	Linklist headc, hc, qc;
	hc = (Linklist)malloc(sizeof(Lnode));
	hc->next = NULL;
	headc = hc;
	while (qa || qb)
	{
		qc = (Linklist)malloc(sizeof(Lnode));
		switch (compare(qa, qb))
		{
		case 1:
		{
			qc->coef = qa->coef;
			qc->expn = qa->expn;
			qa = qa->next;
			break;
		}
		case 0:
		{
			qc->coef = qa->coef + qb->coef;
			qc->expn = qa->expn;
			qa = qa->next;
			qb = qb->next;
			break;
		}
		case -1:
		{
			qc->coef = qb->coef;
			qc->expn = qb->expn;
			qb = qb->next;
			break;
		}
		}
		if (qc->coef != 0)
		{
			qc->next = hc->next;
			hc->next = qc;
			hc = qc;
		}
		else free(qc);
	}
	return headc;
}
void print(Linklist P)
{
	Linklist q = P->next;
	int flag = 1;//项数计数器
	if (!q) 
	{   //若多项式为空，输出0
		putchar('0');
		printf("\n");
		return;
	}
	while (q)
	{
		if (q->coef>0 && flag != 1) 
			putchar('+'); //系数大于0且不是第一项
		if (q->coef != 1 && q->coef != -1)
		{   //系数非1或-1的普通情况
			printf("%g", q->coef);
			if (q->expn == 1) putchar('x');
			else if (q->expn) printf("x^%d", q->expn);
		}
		else
		{
			if (q->coef == 1)
			{
				if (!q->expn) putchar('1');
				else if (q->expn == 1) putchar('x');
				else printf("x^%d", q->expn);
			}
			if (q->coef == -1){
				if (!q->expn) printf("-1");
				else if (q->expn == 1) printf("-x");
				else printf("-x^%d", q->expn);
			}
		}
		q = q->next;
		flag++;
	}
	printf("\n");
}
int main()
{
	Linklist pa = 0, pb = 0, pc;
	int m, n = 0;
	printf("输入a的项数:");
	scanf("%d", &n);
	pa = Creat(pa, n);
	printf("多项式a：");
	print(pa);
	printf("输入b的项数:");
	scanf("%d", &m);
	pb = Creat(pb, m);
	printf("多项式b：");
	print(pb);
	pc = Add(pa, pb);
	printf("多项式a+b："); 
	print(pc);
	return 0;
}
