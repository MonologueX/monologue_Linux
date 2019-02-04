#include "wu_game.h"

void menu()
{
	printf("=============================\n");
	printf("====       主 菜 单      ====\n");
	printf("=============================\n");
	printf("====       1. play       ====\n");
	printf("====       0. exit       ====\n");
	printf("=============================\n");
}

//初始化棋盘
void Init(char map[ROW][COL])
{
	memset(map, '+', ROW*COL*sizeof(char));
	FILE* fp = fopen("./test.c", "a+");
	if (fp == NULL)
    {
		printf("fopen error\n");
	}
    else
    {
		fputs("Test1: game init is OK!",fp);
	}
}

// 打印
void Print(char map[ROW][COL]) 
{
	int i = 0, j = 0, k = 0;
	printf("    Y--------------------------->\n");
	printf("    ");
	for (k = 0; k < COL; k++) 
	{
		if (k >= 0 && k <= 8)
		{
			printf("%d ", k + 1);
		}
		else
		{
			printf("%d", k + 1);
		}
	}
	putchar('\n');
	for (i = 0; i < ROW; i++)
	{
		printf("X");
		if (i >= 0 && i <= 8)
		{
			printf("0%d ", i + 1);
		}
		else
		{
			printf("%d ", i + 1);
		}

		for (j = 0; j < ROW; j++) 
		{
            if (map[i][j] == '+')
            {
			    putchar(map[i][j]);
            }
            else if (map[i][j] == BLACK_FLAG)
            {
                printf("%c", map[i][j]);
            }
            else 
            {
                printf("%c", map[i][j]);
            }
			if (j<(ROW - 1)) 
            {
                putchar('-');
            }
		}
		putchar('\n');
	}
}

int Row(char map[ROW][COL], int row, int col, char whoFlag)
{
	int spaceNum = 0;//空白数
	int count = 1;//几连，包含当前要下的子
	int leftHad = 0;//左边是否有同子
	int x = row;
	int y = col;
	int liveLeft = 0;
	int liveRight = 0;
	if (map[row][col] != '+')
	{
		return 0;
	}
	while (y>0 && (map[x][y - 1] == '+' || map[x][y - 1] == whoFlag))
	{
		if (map[x][y - 1] == '+' && spaceNum < 1)
		{
			//第一个空白
			if (map[x][y - 2] != whoFlag)
			{
				liveLeft = 1;
				break;
			}
			spaceNum++;
			y--;
		}
		else if (map[x][y - 1] == whoFlag)
		{
			leftHad = 1;
			y--;
			count++;
		}
		else
		{
			//第2个空白
			liveLeft = 1;
			break;
		}
	}
	//如果左边没有同色子，设置空白数为0
	if (!leftHad)
	{
		spaceNum = 0;
	}
	y = col;
	while (y<14 && (map[x][y + 1] == '+' || map[x][y + 1] == whoFlag))
	{
		if (map[x][y + 1] == '+' && spaceNum < 1)
		{
			//第一个空白
			if (map[x][y + 2] != whoFlag)
			{
				liveRight = 1;
				break;
			}
			spaceNum++;
			y++;
		}
		else if (map[x][y + 1] == '+' && spaceNum > 0)
		{
			//第2个空白
			liveRight = 1;
			break;
		}
		else
		{
			y++;
			count++;
		}
	}
	return Result(liveLeft, liveRight, count, spaceNum, whoFlag);
}

int Col(char map[ROW][COL], int row, int col, char whoFlag)
{
	int spaceNum = 0;//空白数
	int count = 1;//几连，包含当前要下的子
	int topHad = 0;//上边是否有同子
	int x = row;
	int y = col;
	int liveLeft = 0;
	int liveRight = 0;
	if (map[row][col] != '+')
	{
		return 0;
	}
	while (x > 0 && (map[x - 1][y] == '+' || map[x - 1][y] == whoFlag))
	{
		if (map[x - 1][y] == '+' && spaceNum < 1)
		{
			//第一个空白 
			if (map[x - 2][y] != whoFlag)
			{ 
				liveLeft = 1; 
				break; 
			} 
			spaceNum++; 
			x--; 
		}
		else if (map[x - 1][y] == whoFlag)
		{ 
			topHad = 1; 
			x--; 
			count++; 
		}
		else
		{
			//第2个空白 
			liveLeft = 1; 
			break;
		}
	}
	//如果左边没有同色子，设置空白数为0
	if (!topHad)
	{
		spaceNum = 0;
	}
	x = row;
	while (x < 14 && (map[x + 1][y] == '+' || map[x + 1][y] == whoFlag))
	{
		if (map[x + 1][y] == '+' && spaceNum < 1)
		{
			//第一个空白
			if (map[x + 2][y] != whoFlag)
			{
				liveRight = 1;
				break;
			}
			spaceNum++;
			x++;
		}
		else if (map[x + 1][y] == '+' && spaceNum > 0)
		{
			//第2个空白
			liveRight = 1;
			break;
		}
		else
		{
			x++;
			count++;
		}
	}
	return Result(liveLeft, liveRight, count, spaceNum, whoFlag);
}

// 左斜
int zuoxie(char map[ROW][COL], int row, int col, char whoFlag)
{
	int spaceNum = 0;//空白数
	int count = 1;//几连，包含当前要下的子
	int topHad = 0;//上边是否有同子
	int x = row;
	int y = col;
	int liveLeft = 0;
	int liveRight = 0;
	if (map[row][col] != '+')
	{
		return 0;
	}
	//向下
	while (x < 14 && y>0 && (map[x + 1][y - 1] == '+' || map[x + 1][y - 1] == whoFlag))
	{
		if (map[x + 1][y - 1] == '+' && spaceNum < 1)
		{
			//第一个空白
			if (map[x + 2][y - 2] != whoFlag)
			{
				liveLeft = 1;
				break; 
			} 
			spaceNum++; 
			x++; 
			y--; 
		}
		else if (map[x + 1][y - 1] == whoFlag)
		{ 
			topHad = 1; 
			x++; 
			y--; 
			count++; 
		}
		else
		{
			//第2个空白 
			liveLeft = 1; 
			break; 
		} 
	} 
	//如果上边没有同色子，设置空白数为0 
	if (!topHad)
	{ 
		spaceNum = 0; 
	} 
	x = row; 
	y = col;  
	//向上 
	while (x > 0 && y < 14 && (map[x - 1][y + 1] == '+' || map[x - 1][y + 1] == whoFlag))
	{
		if (map[x - 1][y + 1] == '+' && spaceNum < 1)
		{
			//第一个空白
			if (map[x - 2][y + 2] != whoFlag)
			{
				liveRight = 1;
				break;
			}
			spaceNum++;
			x--;
			y++;
		}
		else if (map[x - 1][y + 1] == '+' && spaceNum > 0)
		{
			//第2个空白
			liveRight = 1;
			break;
		}
		else
		{
			x--;
			y++;
			count++;
		}
	}
	return Result(liveLeft, liveRight, count, spaceNum, whoFlag);
}

// 右斜
int youxie(char map[ROW][COL], int row, int col, char whoFlag)
{ 
	int spaceNum = 0;//空白数 
	int count = 1;//几连，包含当前要下的子 
	int topHad = 0;//上边是否有同子 
	int x = row; 
	int y = col; 
	int liveLeft = 0;
	int liveRight = 0;
	if (map[row][col] != '+')
	{
		return 0;
	}
	//向上
	while (x > 0 && y > 0 && (map[x - 1][y - 1] == '+' || map[x - 1][y - 1] == whoFlag))
	{
		if (map[x - 1][y - 1] == '+' && spaceNum < 1)
		{
			//第一个空白
			if (map[x - 2][y - 2] != whoFlag)
			{
				liveLeft = 1;
				break;
			}
			spaceNum++;
			x--;
			y--;
		}
		else if (map[x - 1][y - 1] == whoFlag)
		{
			topHad = 1;
			x--;
			y--;
			count++;
		}
		else
		{
			//第2个空白
			liveLeft = 1;
			break;
		}
	}
	//如果上边没有同色子，设置空白数为0
	if (!topHad)
	{
		spaceNum = 0;
	}
	x = row;
	y = col;
	//向下
	while (x < 14 && y < 14 && (map[x + 1][y + 1] == '+' || map[x + 1][y + 1] == whoFlag))
	{
		if (map[x + 1][y + 1] == '+' && spaceNum < 1)
		{
			//第一个空白
			if (map[x + 2][y + 2] != whoFlag)
			{
				liveRight = 1; 
				break;
			}
			spaceNum++;
			x++;
			y++;
		}
		else if (map[x + 1][y + 1] == '+' && spaceNum > 0)
		{
			//第2个空白
			liveRight = 1; 
			break; 
		}
		else
		{ 
			x++; 
			y++; 
			count++; 
		}
	}
	return Result(liveLeft, liveRight, count, spaceNum, whoFlag);
}

// 结果
int Result(int left, int right, int count, int k, char num)
{
	if (count == 1)
	{
		return 1;
	}
	else if (count == 2)
	{
		if (left && right)
		{
			//左右两边都是空的
			if (k == 0)
			{
				//电脑60
				return num == WHITE_FLAG ? 60 : 50;
			}
			else
			{
				return num == WHITE_FLAG ? 40 : 35;
			}
		}
		else if (!left && !right)
		{
			return 1;
		}
		else
        {
			return 10;
		}
	}
	else if (count == 3)
	{
		if (left && right)
		{
			//左右两边都是空的
			if (k == 0)
			{
				//电脑950
				return num == WHITE_FLAG ? 950 : 700;
			}
			else
			{
				return num == WHITE_FLAG ? 900 : 650;
			}
		}
		else if (!left && !right)
		{
			return 1;
		}
		else
		{ 
			return 100;
		}
	}
	else if (count == 4)
	{
		if (left && right)
		{
			//左右两边都是空的
			if (k == 0)
			{ 
				return num == WHITE_FLAG ? 6000 : 3500; 
			}
			else
			{ 
				return num == WHITE_FLAG ? 5000 : 3000; 
			} 
		}
		else if (!left && !right)
		{ 
			return 1; 
		}
		else
		{ 
			if (k == 0)
			{ 
				return num == WHITE_FLAG ? 4000 : 800; 
			}
			else{ 
				return num == WHITE_FLAG ? 3600 : 750; 
			} 
		} 
	}
	else
	{ 
		if (k == 0)
		{ 
			return num == WHITE_FLAG ? 20000 : 15000; 
		}
		else
		{ 
			return num == WHITE_FLAG ? 10000 : 3300; 
		} 
	} 
}

//记分
void jifeng(char map[ROW][COL])
{
	int n = 0;
	int m = 0;
	for (n = 0; n < 15; n++)
    {
		for (m = 0; m < 15; m++)
        {
			ComputerScore[n][m] = Row(map, n, m, WHITE_FLAG) + Col(map, n, m, WHITE_FLAG) + zuoxie(map, n, m, WHITE_FLAG) + youxie(map, n, m, WHITE_FLAG);
			PlayScore[n][m] = Row(map, n, m, BLACK_FLAG) + Col(map, n, m, BLACK_FLAG) + zuoxie(map, n, m, BLACK_FLAG) + youxie(map, n, m, BLACK_FLAG);
		}
	}
}

void ComputerPlay(char map[ROW][COL], wuziqi *game)
{ 
	if(NULL == game)
    {
		return;
	}
	jifeng(map); 

	int count = 0; 
	int row = 0; 
	int col = 0; 
	int i = 0;  
	int j = 0; 
	for (i = 0; i < 15; i++)
	{ 
		for (j = 0; j < 15; j++)
		{ 
			if (ComputerScore[i][j] > count)
            {
				count = ComputerScore[i][j];
				row = i; 
				col = j; 
			} 
			if (PlayScore[i][j] > count)
			{ 
				count = PlayScore[i][j]; 
				row = i; 
				col = j;
			}
		}
	}
	printf("ComputerScore[%d][%d]:%d\n", row, col, ComputerScore[row][col]);
	printf("PlayScore[%d][%d]:%d\n", row, col, PlayScore[row][col]);
	if (map[row][col] == '+')
	{
	    map[row][col] = WHITE_FLAG;
		game->row = row;
		game->col = col;
        player = WHITE;
	}
}

//玩家下子
int Play(char map[ROW][COL], wuziqi *game)
{
	if(NULL == game)
    {
		return -1;
	}
	int x, y;
	int res;
	printf("input y x:");
	scanf("%d %d", &x, &y);
	if (x<0 || y<0 || x>COL || y>ROW)
	{
		printf("input error,again\n");
		while ((getchar()) != '\n');
		res = Play(map, game);
		if (res == 1) 
			return 1;
	}
	x--;
	y--;
	if (map[x][y] == '+')
	{
		map[x][y] = BLACK_FLAG;
	    game->row = x;
	    game->col = y;
        player = BLACK;
	}
	else
	{
		printf("input error2,again\n");
		while ((getchar()) != '\n');
		Play(map, game);
		if (res == 1) 
			return 1;
	}
	return 1;
}

int IsWin(char map[ROW][COL], char ch) 
{
	char m = ch;
	int i, j;
	for (i = 0; i < COL; i++) 
	{
		for (j = 0; j < ROW; j++) 
		{
			if (map[i][j] == m) 
			{
				if ((i + 4) < COL) 
				{
					if (map[i + 1][j] == m && map[i + 2][j] == m && map[i + 3][j] == m && map[i + 4][j] == m) 
                        return 1;
				}
				if ((j + 4) < ROW) 
				{
					if (map[i][j + 1] == m && map[i][j + 2] == m && map[i][j + 3] == m && map[i][j + 4] == m) 
                        return 1;
				}
				if ((i + 4) < COL && (j + 4) < ROW) 
				{
					if (map[i + 1][j + 1] == m && map[i + 2][j + 2] == m && map[i + 3][j + 3] == m && map[i + 4][j + 4] == m)
                        return 1;
				}
				if ((i + 4) < COL && (j - 4) >= 0) 
                {
					if (map[i + 1][j - 1] == m && map[i + 2][j - 2] == m && map[i + 3][j - 3] == m && map[i + 4][j - 4] == m) 
                        return 1;
				}
			}
		}
	}
	return 0;
}
