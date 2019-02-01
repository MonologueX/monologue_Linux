#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>

void Init(int array[3][3])
{
	int i, j = 0;
	for (i = 0; i < 3; i++)
	for (j = 0; j < 3; j++)
	{
		array[i][j] = 0;
	}
}

void Print(int array[3][3])
{
	system("cls");
	printf("==========三子棋==========\n");
	int i, j = 0;
	for (i = 0; i < 3; i++)
	{
		printf("\t");
		for (j = 0; j < 3; j++)
		{
			if (array[i][j] == 0)
			{
				printf("   ");
				if (j < 3 - 1)
					printf("|");
			}
			if (array[i][j] == 1)
			{
				printf(" X ");
				if (j < 3 - 1)
					printf("|");
			}
			if (array[i][j] == 4)
			{
				printf(" O ");
				if (j < 3 - 1)
					printf("|");
			}
		}
		printf("\n");
		if (i < 3 - 1)
		{
			printf("\t");
			for (j = 0; j < 3; j++)
			{
				if (i < 3 - 1)
					printf("---");
				if (j < 3 - 1)

					printf("|");
			}
			printf("\n");
		}
	}
	printf("注意：坐标由数字1、2、3组成，例如：3 2\n");
}

int IsWine(int array[3][3])
{
	int i, j = 0;
	int sum = 0;
	for (i = 0; i < 3; i++)
	{
		sum = 0;
		for (j = 0; j < 3; j++)
		{
			sum = sum + array[i][j];
		}
		if (3 == sum || 12 == sum)
		{
			return 1;
		}
	}

	for (j = 0; j < 3; j++)
	{
		sum = 0;
		for (i = 0; i < 3; i++)
		{
			sum = sum + array[i][j];
		}
		if (3 == sum || 12 == sum)
		{
			return 1;
		}
	}

	int win = 0;
	win = array[0][0] + array[1][1] + array[2][2];
	if (3 == win || 12 == win)
	{
		return 1;
	}

	win = array[0][2] + array[1][1] + array[2][0];
	if (3 == win || 12 == win)
	{
		return 1;
	}
	while (1)
	{
		for (j = 0; j < 3; j++)
		{
			for (i = 0; i < 3; i++)
			{
				if (0 == array[i][j])
					return 0;
			}
		}
		return 2;
	}
	return 0;
}

void PlayMove(int array[3][3])
{
	int row, col = 0;

	while (1)
	{
		printf("请输入坐标：");
		scanf("%d %d", &row, &col);
		if ((row <= 0 && row >= 4) && (col <= 0 && col >= 4))
		{
			system("cls");
			printf("坐标不合法！！！\n");
			continue;
		}
		if (0 == array[row - 1][col - 1])
		{
			array[row - 1][col - 1] = 1;
			break;
		}
		else
			printf("您输入的坐标被占用 !!!\n");
	}
}

void ComputerMove(int array[3][3])
{
	int i, j = 0;
	int sum = 0;
	for (i = 0; i < 3; i++)
	{
		sum = 0;
		for (j = 0; j < 3; j++)
		{
			sum = sum + array[i][j];
		}
		if (sum >= 8)
		{
			for (j = 0; j < 3; j++)
			{
				if (0 == array[i][j])
				{
					array[i][j] = 4;
					return;
				}
			}
		}
	}
	for (j = 0; j < 3; j++)
	{
		sum = 0;
		for (i = 0; i < 3; i++)
		{
			sum = sum + array[i][j];
		}
		if (sum >= 8)
		{
			for (i = 0; i < 3; i++)
			{
				if (0 == array[i][j])
				{
					array[i][j] = 4;
					return;
				}
			}
		}
	}
	sum = array[0][0] + array[1][1] + array[2][2];
	if (sum >= 8)
	{
		for (i = 0; i < 3; i++)
		{
			if (0 == array[i][i])
			{
				array[i][i] = 4;
				return;
			}
		}
	}
	sum = array[0][2] + array[1][1] + array[2][0];
	if (sum >= 8)
	{
		for (i = 0; i < 3; i++)
		{
			if (0 == array[i][2 - i])
			{
				array[i][i - 2] = 4;
				return;
			}
		}
	}

	for (i = 0; i < 3; i++)
	{
		sum = 0;
		for (j = 0; j < 3; j++)
		{
			sum = sum + array[i][j];
		}
		if (sum == 2 || sum == 6)
		{
			for (j = 0; j < 3; j++)
			{
				if (0 == array[i][j])
				{
					array[i][j] = 4;
					return;
				}
			}
		}
	}
	for (j = 0; j < 3; j++)
	{
		sum = 0;
		for (i = 0; i < 3; i++)
		{
			sum = sum + array[i][j];
		}
		if (sum == 2 || sum == 6)
		{
			for (i = 0; i < 3; i++)
			{
				if (0 == array[i][j])
				{
					array[i][j] = 4;
					return;
				}
			}
		}
	}
	sum = array[0][0] + array[1][1] + array[2][2];
	if (sum == 2 || sum == 6)
	{
		for (i = 0; i < 3; i++)
		{
			if (0 == array[i][i])
			{
				array[i][i] = 4;
				return;
			}
		}
	}
	sum = array[0][2] + array[1][1] + array[2][0];
	if (sum == 2 || sum == 6)
	{
		for (i = 0; i < 3; i++)
		{
			if (0 == array[i][2 - i])
			{
				array[i][i - 2] = 4;
				return;
			}
		}
	}

	if (0 == array[1][1])
	{
		array[1][1] = 4;
		return;
	}

	for (i = 0; i < 3; i += 2)
	{
		for (j = 0; j < 3; j += 2)
		if (0 == array[i][j])
		{
			array[i][j] = 4;
			return;
		}

	}

	system("cls");
	printf("电脑正在思考！！！\n");
	while (1)
	{
		srand(time(NULL));
		i = rand() % 3;
		j = rand() % 3;
		if (0 == array[i][j])
		{
			system("cls");
			array[i][j] = 4;
			break;
		}
	}

}

void Menu1()
{
	printf("Wlecome to play game!!!\n");
	printf("     1.play \n");
	printf("     0.exit \n");
	printf("请选择：");
}

void Menu2()
{
	system("cls");
	printf("Wlecome to play game!!!\n");
	printf("     1.电脑先走 \n");
	printf("     2.玩家先走 \n");
	printf("请选择：");
}

void play()
{
	int choices = 0;
	int array[3][3] = { 0 };
	int win = 0;
	while (1)
	{
		Menu1();
		scanf("%d", &choices);
		if (0 == choices)
			return;
		while (1)
		{
			Menu2();
			scanf("%d", &choices);
			Init(array);
			if (1 == choices)
				goto Part1;
			Print(array);
			while (1)
			{
				PlayMove(array);
				Print(array);
				win = IsWine(array);
				if (1 == win)
				{
					printf("您真厉害！！！\n");
					break;
				}
				else if (2 == win)
				{
					printf("平局！！！\n");
					break;
				}
			Part1:
				ComputerMove(array);
				Print(array);
				win = IsWine(array);
				if (1 == win)
				{
					printf("很遗憾您输了！！！\n");
					break;
				}
				else if (2 == win)
				{
					printf("平局！！！\n");
					break;
				}
			}
			break;
		}
	}
}

int main()
{
	play();
	return 0;
}