/***********************************
 * 文件名称: main.c
 * 文件描述: 
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <error.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

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
	printf("注意：坐标由数字1、2、3组成，例如：3,2\n");
}

int main()
{
    int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sockfd <0)
    {
        perror("scoket error");
        return -1;
    }
    struct sockaddr_in addr;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(9000);
    // addr.sin_addr.s_addr = htonl(0xc0a8f18b);
    ///////////////////////////////
    // 另一种写法
    addr.sin_addr.s_addr = inet_addr("192.168.241.139");
    socklen_t len = sizeof(struct sockaddr_in);
    int ret;
    ret = bind(sockfd, (struct sockaddr*)&addr, len);
    if (ret < 0)
    {
        perror("bind error\n");
        return -1;
    }

    while (1)
    {
        char buff[1024] = {0};
        struct sockaddr_in cli_addr;
        recvfrom(sockfd, buff, 1023, 0, (struct sockaddr*)&cli_addr, &len);
        printf("client say: %s\n", buff);

        memset(buff, 0x00, 1024);
        scanf("%s", buff);

        sendto(sockfd, buff, strlen(buff), 0, (struct sockaddr*)&cli_addr, len);
    }
    close(sockfd);
    return 0;
}
