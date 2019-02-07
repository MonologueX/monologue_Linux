/***********************************
 * 文件名称: client.c
 * 文件描述: UDP 客户端
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "proto.h"

typedef struct sockaddr sockaddr;
typedef struct sockaddr_in sockaddr_in;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage ./client [ip] [port]\n");
        return 1;
    }
    int fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd < 0)
    {
        perror("socket error");
        return -1;
    }
    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));
    while (1)
    {
        Request req;
        printf("输入第一个数字:");
        fflush(stdout);
        scanf("%d", &req.a);
        printf("输入第二个数字:");
        fflush(stdout);
        scanf("%d", &req.b);

        req.a = htonl(req.a);
        req.b = htonl(req.b);

        sendto(fd, &req, sizeof(req), 0, (sockaddr*)&server_addr, sizeof(server_addr));
        Response resp;
        ssize_t read_size = recvfrom(fd, &resp, sizeof(resp), 0, NULL, NULL);
        if (read_size < 0)
        {
            perror("recvfrom error");
            continue;
        }
        resp.sum = ntohl(resp.sum);
        printf("server resp: sum=%d\n", resp.sum);
    }
    return 0;
}
