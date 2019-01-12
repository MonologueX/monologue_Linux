#include <stdio.h>
#include <unistd.h>
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
        printf("Usage:%s ip port\n", argv[0]);
        return 1;
    }
    
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("socket error");
        return 2;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0)
    {
        perror("connect error");
        return 3;
    }

    char buf[1024];
    while (1)
    {
        printf("Please enter:");
        scanf("%s", buf);
        write(sock, buf, strlen(buf));
    }
    return 0;
}
