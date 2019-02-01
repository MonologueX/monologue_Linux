#include "san_game.h"

void Init(sanziqi **san)
{
	int i, j = 0;
	for (i = 0; i < 3; i++)
	for (j = 0; j < 3; j++)
	{
		(*san)->array[i][j] = 0;
	}
}

void Print(sanziqi *san)
{
	printf("==========三子棋==========\n");
	int i, j = 0;
	for (i = 0; i < 3; i++)
	{
		printf("\t");
		for (j = 0; j < 3; j++)
		{
			if (san->array[i][j] == 0)
			{
				printf("   ");
				if (j < 3 - 1)
					printf("|");
			}
			if (san->array[i][j] == 1)
			{
				printf(" X ");
				if (j < 3 - 1)
					printf("|");
			}
			if (san->array[i][j] == 4)
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

void PlayMove(sanziqi **san)
{
	int row, col = 0;

	while (1)
	{
		printf("请输入坐标：");
		scanf("%d %d", &row, &col);
		if ((row <= 0 && row >= 4) && (col <= 0 && col >= 4))
		{
			printf("坐标不合法！！！\n");
			continue;
		}
		if (0 == (*san)->array[row - 1][col - 1])
		{
			(*san)->array[row - 1][col - 1] = 1;
			break;
		}
		else
			printf("您输入的坐标被占用 !!!\n");
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
	printf("Wlecome to play game!!!\n");
	printf("     1.电脑先走 \n");
	printf("     2.玩家先走 \n");
	printf("请选择：");
}

int IsWin(sanziqi *san)
{
	int i, j = 0;
	int sum = 0;
	for (i = 0; i < 3; i++)
	{
		sum = 0;
		for (j = 0; j < 3; j++)
		{
			sum = sum + san->array[i][j];
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
			sum = sum + san->array[i][j];
		}
		if (3 == sum || 12 == sum)
		{
			return 1;
		}
	}

	int win = 0;
	win = san->array[0][0] + san->array[1][1] + san->array[2][2];
	if (3 == win || 12 == win)
	{
		return 1;
	}

	win = san->array[0][2] + san->array[1][1] + san->array[2][0];
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
				if (0 == san->array[i][j])
					return 0;
			}
		}
		return 2;
	}
	return 0;
}

void ComputerMove(sanziqi **san)
{
	int i, j = 0;
	int sum = 0;
	for (i = 0; i < 3; i++)
	{
		sum = 0;
		for (j = 0; j < 3; j++)
		{
			sum = sum + (*san)->array[i][j];
		}
		if (sum >= 8)
		{
			for (j = 0; j < 3; j++)
			{
				if (0 == (*san)->array[i][j])
				{
					(*san)->array[i][j] = 4;
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
			sum = sum + (*san)->array[i][j];
		}
		if (sum >= 8)
		{
			for (i = 0; i < 3; i++)
			{
				if (0 == (*san)->array[i][j])
				{
					(*san)->array[i][j] = 4;
					return;
				}
			}
		}
	}
	sum = (*san)->array[0][0] + (*san)->array[1][1] + (*san)->array[2][2];
	if (sum >= 8)
	{
		for (i = 0; i < 3; i++)
		{
			if (0 == (*san)->array[i][i])
			{
				(*san)->array[i][i] = 4;
				return;
			}
		}
	}
	sum = (*san)->array[0][2] + (*san)->array[1][1] + (*san)->array[2][0];
	if (sum >= 8)
	{
		for (i = 0; i < 3; i++)
		{
			if (0 == (*san)->array[i][2 - i])
			{
				(*san)->array[i][i - 2] = 4;
				return;
			}
		}
	}

	for (i = 0; i < 3; i++)
	{
		sum = 0;
		for (j = 0; j < 3; j++)
		{
			sum = sum + (*san)->array[i][j];
		}
		if (sum == 2 || sum == 6)
		{
			for (j = 0; j < 3; j++)
			{
				if (0 == (*san)->array[i][j])
				{
					(*san)->array[i][j] = 4;
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
			sum = sum + (*san)->array[i][j];
		}
		if (sum == 2 || sum == 6)
		{
			for (i = 0; i < 3; i++)
			{
				if (0 == (*san)->array[i][j])
				{
					(*san)->array[i][j] = 4;
					return;
				}
			}
		}
	}
	sum = (*san)->array[0][0] + (*san)->array[1][1] + (*san)->array[2][2];
	if (sum == 2 || sum == 6)
	{
		for (i = 0; i < 3; i++)
		{
			if (0 == (*san)->array[i][i])
			{
				(*san)->array[i][i] = 4;
				return;
			}
		}
	}
	sum = (*san)->array[0][2] + (*san)->array[1][1] + (*san)->array[2][0];
	if (sum == 2 || sum == 6)
	{
		for (i = 0; i < 3; i++)
		{
			if (0 == (*san)->array[i][2 - i])
			{
				(*san)->array[i][i - 2] = 4;
				return;
			}
		}
	}

	if (0 == (*san)->array[1][1])
	{
		(*san)->array[1][1] = 4;
		return;
	}

	for (i = 0; i < 3; i += 2)
	{
		for (j = 0; j < 3; j += 2)
		if (0 == (*san)->array[i][j])
		{
			(*san)->array[i][j] = 4;
			return;
		}

	}

	printf("电脑正在思考！！！\n");
	while (1)
	{
		srand(time(NULL));
		i = rand() % 3;
		j = rand() % 3;
		if (0 == (*san)->array[i][j])
		{
			(*san)->array[i][j] = 4;
			break;
		}
	}
}
