/***********************************
 * 文件名称: cal_servc
 * 文件描述: 三子棋
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
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

	printf("电脑正在思考！！！\n");
	while (1)
	{
		srand(time(NULL));
		i = rand() % 3;
		j = rand() % 3;
		if (0 == array[i][j])
		{
			array[i][j] = 4;
			break;
		}
	}

}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        perror("Usage:./cal.c ip port \n");
        return 1;
    }
    int listen_fd, new_fd, ret;
    socklen_t len;
    struct sockaddr_in listen_addr;
    struct sockaddr_in client_addr;

    listen_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listen_fd < 0)
    {
        perror("socket error");
        return 2;
    }

    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(atoi(argv[2]));
    listen_addr.sin_addr.s_addr = inet_addr(argv[1]);
    len = sizeof(struct sockaddr_in);
    ret = bind(listen_fd, (struct sockaddr*)&listen_addr, len);
    if (ret < 0)
    {
        perror("bind error");
        return 3;
    }
    if (listen(listen_fd, 5) < 0)
    {
        perror("listen error");
        return 4;
    }
    while (1)
    {
        new_fd = accept(listen_fd, (struct sockaddr*)&client_addr, &len);
        if (new_fd < 0)
        {
            perror("accept error"); 
            continue;
        }
        char buf[1024] = {0};
        ssize_t rlen = recv(new_fd, buf, 1024, 0);
        if (rlen < 0)
        {
            perror("recv error");
            return 5;
        }
        else if (rlen == 0)
        {
            printf("peer shutdown !!!\n");
            close(new_fd);
            continue;
        }
        sanziqi *san = (sanziqi*)buf; 
        IsWine(san->array);
        ComputerMove(san->array);
        send(new_fd, (void*)&san, sizeof(san), 0);
        close(new_fd);
    }

    return 0;
}
