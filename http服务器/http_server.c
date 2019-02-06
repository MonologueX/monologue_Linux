/***********************************
 * 文件名称: http_server.c
 * 文件描述: 返回 hello word
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef struct sockaddr sockaddr;
typedef struct sockaddr_in sockaddr_in;

int ServerInit(const char *ip, short port)
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
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
    ret = listen(fd, 5);
    if (ret < 0)
    {
        perror("listen error");
        return -1;
    }
    return fd;
}

void *ThreadEntry(void *arg)
{
    int64_t new_sock = (int64_t)arg;
    char buf[1024*10] = {0};
    read(new_sock, buf, sizeof(buf) - 1);
    printf("[Request]%s\n", buf);

    const char *first_line = "HTTP/1.1 200 OK\n";
    const char *blank_line = "\n";
    const char *body = "<html>hello word</html>";
    char header[1024*10] = {0};
    sprintf(header, "Content-Type:text/html;\nContent-Length:%lu\n", strlen(body));
    write(new_sock, first_line, strlen(first_line));
    write(new_sock, header, strlen(header));
    write(new_sock, blank_line, strlen(blank_line));
    write(new_sock, body, strlen(body));
    return NULL;
}


int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage ./http_server [ip] [port]\n");
        return 1;
    }
    int listen_sock = ServerInit(argv[1], atoi(argv[2]));
    if (listen_sock < 0)
    {
        printf("ServerInit failed\n");
        return 1;
    }
    printf("ServerInit OK\n");
    while (1)
    {
        sockaddr_in peer;
        socklen_t len = sizeof(peer);
        int64_t new_sock = accept(listen_sock, (sockaddr*)&peer, &len);
        if (new_sock < 0)
        {
            perror("accept error");
            continue;
        }
        pthread_t tid;
        pthread_create(&tid, NULL, ThreadEntry, (void *)new_sock);
        pthread_detach(tid);
    }
    return 0;
}
