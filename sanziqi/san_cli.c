/***********************************
 * 文件名称: cal_cli.c
 * 文件描述: 三子棋
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

typedef struct _sanziqi
{
    int array[3][3];
    int win;
}sanziqi;


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

void PlayMove(int array[3][3])
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
		if (0 == array[row - 1][col - 1])
		{
			array[row - 1][col - 1] = 1;
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

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        perror("Usage:./cal.c ip port \n");
        return 1;
    }
    int sockfd, ret;
    socklen_t len;
    struct sockaddr_in serive_addr;
    sanziqi *san;

    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0)
    {
        perror("socket error");
        return 2;
    }

    serive_addr.sin_family = AF_INET;
    serive_addr.sin_port = htons(atoi(argv[2]));
    serive_addr.sin_addr.s_addr = inet_addr(argv[1]);
    len = sizeof(struct sockaddr_in);
    ret = connect(sockfd, (struct sockaddr*)&serive_addr, len);
    if (ret < 0)
    {
        perror("connect error");
        return 3;
    }
	int choices = 0;
	while (1)
	{
        Init(san->array);
		Menu1();
		scanf("%d", &choices);
		if (0 == choices)
			return 0;
		while (1)
		{
			Menu2();
			scanf("%d", &choices);
			if (1 == choices)
				goto Part1;
			Print(san->array);
			while (1)
			{
				PlayMove(san->array);
				Print(san->array);
                send(sockfd, (void*)&san, sizeof(san), 0);
                recv(sockfd, (void*)&san, sizeof(san), 0);
                
				if (1 == (san->win))
				{
					printf("您真厉害！！！\n");
					break;
				}
				else if (2 == (san->win))
				{
					printf("平局！！！\n");
					break;
				}
			Part1:
                send(sockfd, (void*)&san, sizeof(san), 0);
                recv(sockfd, (void*)&san, sizeof(san), 0);
				Print((san->array));
				if (1 == (san->win))
				{
					printf("很遗憾您输了！！！\n");
					break;
				}
				else if (2 == (san->win))
				{
					printf("平局！！！\n");
					break;
				}
			}
			break;
		}
	}

    close(sockfd);

    return 0;
}
