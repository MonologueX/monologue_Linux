#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stack>
#include <queue>
using namespace std;
#define MNUM 20

typedef char VertexType; //顶点数据类型 

typedef struct
{
	int vexnum;  //顶点数 
	int arcnum;  //边数 
	VertexType vexs[MNUM]; //顶点数组 
	int  AdjMatrix[MNUM][MNUM];  //邻接矩阵 
	int  visited[MNUM];  //遍历时的访问状态 
}MGraph;  //图的类型 

//图的信息初始化 
void InitMGraph(MGraph *mp)
{
	int i, k;
	mp->vexnum = 0; //顶点数置0 
	mp->arcnum = 0; //边数置0 

	for (i = 0; i < MNUM; i++)
		mp->vexs[i] = '#';  //顶点数据置'#' ,不使用该符号作为顶点 

	for (i = 0; i < MNUM; i++)
		for (k = 0; k < MNUM; k++)
			mp->AdjMatrix[i][k] = 0; //邻接矩阵数据全部置0 

	for (i = 0; i < MNUM; i++)
		mp->visited[i] = 0;   //访问状态为0，假值，表示未访问		
}

//输出图的各个信息 
void PrintGinfo(MGraph *mp)
{
	int i, k;
	printf("\n\n图的信息如下：");

	printf("\n顶点数:%d", mp->vexnum);
	printf("\n顶点信息:");
	for (i = 1; i <= mp->vexnum; i++)
		printf("%c", mp->vexs[i]);

	printf("\n边数:%d", mp->arcnum);
	printf("\n边信息:\n");
	for (i = 1; i <= mp->vexnum; i++)
	{
		for (k = i; k <= mp->vexnum; k++)
			if (mp->AdjMatrix[i][k] == 1)
				printf("(%c,%c) ", mp->vexs[i], mp->vexs[k]);
	}

	printf("\n邻接矩阵:\n");
	for (i = 1; i <= mp->vexnum; i++)
	{
		for (k = 1; k <= mp->vexnum; k++)
			printf("%2d", mp->AdjMatrix[i][k]);
		printf("\n");
	}
}

//读取顶点信息，填写顶点数组 
void creatvexs(MGraph *mp, char filename[20])
{
	FILE  *f;
	int i;
	f = fopen(filename, "r");
	for (i = 1; i <= mp->vexnum; i++)
		fscanf(f, "%c", &mp->vexs[i]);//读取数据,格式为字符型 
	fclose(f);
}

//获取顶点ch的编号，0表示未找到 
int getvid(MGraph *mp, VertexType ch)
{
	int i;
	for (i = 1; i <= mp->vexnum; i++)
		if (mp->vexs[i] == ch) return i;
	return 0;
}

//读取边信息，填写邻接矩阵 
void creatarcs(MGraph *mp, char filename[20])
{
	FILE  *f;
	char  s, t;
	int i, k, m;
	f = fopen(filename, "r");
	for (m = 1; m <= mp->arcnum; m++)
	{
		fscanf(f, "(%c,%c)\n", &s, &t); //读取数据,格式为(a,b) 
		i = getvid(mp, s); //获取编号 
		k = getvid(mp, t); //获取编号 
		if (i&&k)  //编号非0 
		{
			mp->AdjMatrix[i][k] = 1;  //无向图是对称矩阵 
			mp->AdjMatrix[k][i] = 1;
		}
	}
	fclose(f);
}

void DFS1(MGraph *mp, char v)//从顶点v开始递归遍历 
{
	int i, id;
	id = getvid(mp, v); //获取编号
	printf("%c-->", v); //访问，即遍历 
	mp->visited[id] = 1; //设置状态 
	for (i = 1; i <= mp->vexnum; i++)  //查找邻接点 
	{
		if (mp->AdjMatrix[id][i] == 1 && mp->visited[i] == 0) //如果邻接点未访问 
			DFS1(mp, mp->vexs[i]);  //遍历该邻接点 
	}
}

void DFS2(MGraph *mp, char v)  //从顶点v开始非递归遍历 
{
	stack<int> st;

	printf("%c-->", v);                //遍历第一个结点
	int id = getvid(mp, v), j;
	mp->visited[id] = 1;
	//编号进栈
	st.push(getvid(mp,v));
	//printf("%d-->",st.top());
	 
	while (!st.empty())
	{
		for (j = 1; j <= mp->vexnum; j++)            
		{
			if (mp->AdjMatrix[st.top()][j] == 1 && mp->visited[j] == 0)    //查找邻接顶点
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

	//编号入队
	q.push(getvid(mp, v));

	printf("%c-->", v);                //遍历第一个结点
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
		char f1[20] = "vex.txt";//顶点数据文件 
		char f2[20] = "arc.txt";//边数据文件 
		char ch;

		InitMGraph(&mygp);//初始化图变量 

		printf("\n请输入顶点数:");
		scanf("%d", &mygp.vexnum);
		printf("\n请输入边数:");
		scanf("%d", &mygp.arcnum);
		printf("\n正在读取顶点数据......");
		creatvexs(&mygp, f1);
		printf("\n正在读取边信息......");
		creatarcs(&mygp, f2);

		/**********输出图的信息*****************/
		PrintGinfo(&mygp);

		/**********遍历测试***********************/
		printf("\n请输入遍历开始的顶点:");
		scanf("\n%c", &ch);
		printf("\n深度优先遍历（递归）:");
		DFS1(&mygp, ch);
		printf("\n深度优先遍历（非递归）:");
		DFS2(&mygp, ch);
		printf("\n广度优先遍历 :");
		BFS(&mygp, ch);
 }
