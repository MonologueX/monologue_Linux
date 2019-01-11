#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage:%s [ip] [port]\n", argv[0]);
        return 1;
    }

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0)
    {
        perror("socket error");
        return 2;
    }

    struct sockaddr_in local;
    local.sin_family = AF_INET;
    local.sin_port = htons(atoi(argv[2]));
    local.sin_addr.s_addr = inet_addr(argv[1]);

    if (bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0)
    {
        perror("bind error");
        return 3;
    }

    char buf[1024];
    while (1)
    {
        struct sockaddr_in client;
        socklen_t len = sizeof(client);
        ssize_t s = recvfrom(sock, buf, sizeof(buf)-1, 0, (struct sockaddr*)&client, &len);
        if (s > 0)
        {
            buf[s] = 0;
            printf("[%s:%d]:%s", inet_ntoa(client.sin_addr), ntohs(client.sin_port), buf);
            sendto(sock, buf, strlen(buf), 0, (struct sockaddr*)&client, sizeof(client));
        }
    }
    return 0;
}
