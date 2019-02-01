#pragma once 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>

#define ROW 10
#define COL 10

typedef struct my_point
{
	int row;
	int col;
}my_point;

//��ʼ������
void Init(char board[ROW][COL], int row, int col);

//��ӡ����
void Print(char board[ROW][COL], int row, int col);

//�ͻ����ƶ�
void ClientMove(char board[ROW][COL], my_point* point);

//�������ƶ�
void ServerMove(char board[ROW][COL], my_point* point);

//��ͬ�ƶ�
void CommonMove(char board[ROW][COL], my_point* point, char ch);

//�ж���Ӯ
char GameState(char board[ROW][COL], my_point* point);
