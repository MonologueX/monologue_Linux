/***********************************
 * 文件名称: server.c
 * 文件描述: UDP 服务器
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

int ServiceInit(const char *ip, short port)
{
    int fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd < 0)
    {
        perror("socket error");
        return -1;
    }
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(port);
    int ret = bind(fd, (sockaddr*)&addr, sizeof(addr));
    if (ret < 0)
    {
        perror("bind error");
        return -1;
    }
    return fd;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage ./server [ip] [port]\n");
        return 1;
    }
    int fd = ServiceInit(argv[1], atoi(argv[2]));
    if (fd < 0)
    {
        printf("ServerInit failed\n");
        return 1;
    }
    printf("ServerInit OK\n");
    while (1)
    {
        sockaddr_in peer;
        socklen_t len = sizeof(peer);
        Request req;
        ssize_t read_size = recvfrom(fd, &req, sizeof(req), 0, (sockaddr*)&peer, &len);
        if (read_size < 0)
        {
            perror("recvfrom error");
            continue;
        }
        // 转换成主机字节序
        req.a = ntohl(req.a);
        req.b = ntohl(req.b);
        printf("[Request] a=%d, b=%d\n", req.a, req.b);
        int sum = req.a + req.b;
        Response resp;
        resp.sum = sum;
        printf("[Response] sum=%d\n", resp.sum);
        // 转换成网络字节序
        resp.sum = htonl(resp.sum);
        sendto(fd, &resp, sizeof(resp), 0, (sockaddr*)&peer, len);
    }
    return 0;
}
