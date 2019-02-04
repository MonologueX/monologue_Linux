#define __GAME_H__
#ifdef __GAME_H__ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>

#define ROW 15
#define COL 15
#define BLACK 0
#define WHITE 1 
#define WIN 2

typedef struct wuziqi
{
	int row;
	int col;
}wuziqi;

char BLACK_FLAG = 'O';//大写o
char WHITE_FLAG = '@';
int ComputerScore[ROW][COL] = { 0 };
int PlayScore[ROW][COL] = { 0 };
int player = WHITE;

//初始化棋盘
void Init(char map[ROW][COL]);

//打印棋盘
void Print(char map[ROW][COL]);

// 电脑走棋
int Row(char map[ROW][COL], int row, int col, char whoFlag);
int Col(char map[ROW][COL], int row, int col, char whoFlag);
int zuoxie(char map[ROW][COL], int row, int col, char whoFlag);
int youxie(char map[ROW][COL], int row, int col, char whoFlag);
int Result(int left, int right, int count, int k, char num);
void jifeng(char map[ROW][COL]);
void ComputerPlay(char map[ROW][COL], wuziqi *game);

// 玩家走棋
int Play(char map[ROW][COL], wuziqi *game);

// 判断输赢
int IsWin(char map[ROW][COL], char ch);

// 菜单
void menu();
#endif
