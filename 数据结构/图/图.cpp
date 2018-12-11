#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stack>
#include <queue>
using namespace std;
#define MNUM 20

typedef char VertexType; //������������ 

typedef struct
{
	int vexnum;  //������ 
	int arcnum;  //���� 
	VertexType vexs[MNUM]; //�������� 
	int  AdjMatrix[MNUM][MNUM];  //�ڽӾ��� 
	int  visited[MNUM];  //����ʱ�ķ���״̬ 
}MGraph;  //ͼ������ 

//ͼ����Ϣ��ʼ�� 
void InitMGraph(MGraph *mp)
{
	int i, k;
	mp->vexnum = 0; //��������0 
	mp->arcnum = 0; //������0 

	for (i = 0; i < MNUM; i++)
		mp->vexs[i] = '#';  //����������'#' ,��ʹ�ø÷�����Ϊ���� 

	for (i = 0; i < MNUM; i++)
		for (k = 0; k < MNUM; k++)
			mp->AdjMatrix[i][k] = 0; //�ڽӾ�������ȫ����0 

	for (i = 0; i < MNUM; i++)
		mp->visited[i] = 0;   //����״̬Ϊ0����ֵ����ʾδ����		
}

//���ͼ�ĸ�����Ϣ 
void PrintGinfo(MGraph *mp)
{
	int i, k;
	printf("\n\nͼ����Ϣ���£�");

	printf("\n������:%d", mp->vexnum);
	printf("\n������Ϣ:");
	for (i = 1; i <= mp->vexnum; i++)
		printf("%c", mp->vexs[i]);

	printf("\n����:%d", mp->arcnum);
	printf("\n����Ϣ:\n");
	for (i = 1; i <= mp->vexnum; i++)
	{
		for (k = i; k <= mp->vexnum; k++)
			if (mp->AdjMatrix[i][k] == 1)
				printf("(%c,%c) ", mp->vexs[i], mp->vexs[k]);
	}

	printf("\n�ڽӾ���:\n");
	for (i = 1; i <= mp->vexnum; i++)
	{
		for (k = 1; k <= mp->vexnum; k++)
			printf("%2d", mp->AdjMatrix[i][k]);
		printf("\n");
	}
}

//��ȡ������Ϣ����д�������� 
void creatvexs(MGraph *mp, char filename[20])
{
	FILE  *f;
	int i;
	f = fopen(filename, "r");
	for (i = 1; i <= mp->vexnum; i++)
		fscanf(f, "%c", &mp->vexs[i]);//��ȡ����,��ʽΪ�ַ��� 
	fclose(f);
}

//��ȡ����ch�ı�ţ�0��ʾδ�ҵ� 
int getvid(MGraph *mp, VertexType ch)
{
	int i;
	for (i = 1; i <= mp->vexnum; i++)
		if (mp->vexs[i] == ch) return i;
	return 0;
}

//��ȡ����Ϣ����д�ڽӾ��� 
void creatarcs(MGraph *mp, char filename[20])
{
	FILE  *f;
	char  s, t;
	int i, k, m;
	f = fopen(filename, "r");
	for (m = 1; m <= mp->arcnum; m++)
	{
		fscanf(f, "(%c,%c)\n", &s, &t); //��ȡ����,��ʽΪ(a,b) 
		i = getvid(mp, s); //��ȡ��� 
		k = getvid(mp, t); //��ȡ��� 
		if (i&&k)  //��ŷ�0 
		{
			mp->AdjMatrix[i][k] = 1;  //����ͼ�ǶԳƾ��� 
			mp->AdjMatrix[k][i] = 1;
		}
	}
	fclose(f);
}

void DFS1(MGraph *mp, char v)//�Ӷ���v��ʼ�ݹ���� 
{
	int i, id;
	id = getvid(mp, v); //��ȡ���
	printf("%c-->", v); //���ʣ������� 
	mp->visited[id] = 1; //����״̬ 
	for (i = 1; i <= mp->vexnum; i++)  //�����ڽӵ� 
	{
		if (mp->AdjMatrix[id][i] == 1 && mp->visited[i] == 0) //����ڽӵ�δ���� 
			DFS1(mp, mp->vexs[i]);  //�������ڽӵ� 
	}
}

void DFS2(MGraph *mp, char v)  //�Ӷ���v��ʼ�ǵݹ���� 
{
	stack<int> st;

	printf("%c-->", v);                //������һ�����
	int id = getvid(mp, v), j;
	mp->visited[id] = 1;
	//��Ž�ջ
	st.push(getvid(mp,v));
	//printf("%d-->",st.top());
	 
	while (!st.empty())
	{
		for (j = 1; j <= mp->vexnum; j++)            
		{
			if (mp->AdjMatrix[st.top()][j] == 1 && mp->visited[j] == 0)    //�����ڽӶ���
			{
				printf("%c-->", mp->vexs[j]);
				mp->visited[getvid(mp, mp->vexs[j])] = 1;
				st.push(getvid(mp,mp->vexs[j]));
				break;
			}
		}
		if (j == mp->vexnum+1)
		{
			st.pop();
			//printf("%c-->", mp->vexs[j]);
		}
	}
}

void BFS(MGraph *mp, char v)
{
    queue<int> q;

	//������
	q.push(getvid(mp, v));

	printf("%c-->", v);                //������һ�����
	int id = getvid(mp, v), j;
	mp->visited[id] = 1;

	while (!q.empty())
	{
		for (j = 1; j <= mp->vexnum; j++)
		{
			if (mp->AdjMatrix[q.front()][j] == 1 && mp->visited[j] == 0)
			{
				printf("%c-->", mp->vexs[j]);
				mp->visited[j] = 1;
				q.push(getvid(mp, mp->vexs[j]));
				break;
			}
		}
		if (j == mp->vexnum + 1)
		{
			q.pop();
			//printf("%c-->", mp->vexs[j]);
		}
	}
}

 int main()
{
		MGraph  mygp;
		char f1[20] = "vex.txt";//���������ļ� 
		char f2[20] = "arc.txt";//�������ļ� 
		char ch;

		InitMGraph(&mygp);//��ʼ��ͼ���� 

		printf("\n�����붥����:");
		scanf("%d", &mygp.vexnum);
		printf("\n���������:");
		scanf("%d", &mygp.arcnum);
		printf("\n���ڶ�ȡ��������......");
		creatvexs(&mygp, f1);
		printf("\n���ڶ�ȡ����Ϣ......");
		creatarcs(&mygp, f2);

		/**********���ͼ����Ϣ*****************/
		PrintGinfo(&mygp);

		/**********��������***********************/
		printf("\n�����������ʼ�Ķ���:");
		scanf("\n%c", &ch);
		printf("\n������ȱ������ݹ飩:");
		DFS1(&mygp, ch);
		printf("\n������ȱ������ǵݹ飩:");
		DFS2(&mygp, ch);
		printf("\n������ȱ��� :");
		BFS(&mygp, ch);
 }
