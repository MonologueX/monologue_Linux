#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX 1024

static void usage(const char *proc)
{
    printf("Usage:%s [port]\n", proc);
}

static int startp(int port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("sock error");
        exit(2);
    }

    int opt = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in local;
    local.sin_family = AF_INET;
    local.sin_addr.s_addr = htonl(INADDR_ANY);
    local.sin_port = htons(port);

    if (bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0)
    {
        perror("bind error");
        exit(3);
    }
    if (listen(sock, 5) < 0)
    {
        perror("listen error");
        exit(4);
    }
    return sock;
}

static int getLine(int sock, char line[], int size)
{
    char c = 'a';
    int i = 0;
    while (c != '\n' && i < size - 1)
    {
        ssize_t s = read(sock, &c, 1);
        if (c == '\r')
        {
            recv(sock, &c, 1, MSG_PEEK);
            if (c == '\n')
            {
                recv(sock, &c, 1, 0);
            }
            else 
            {
                c = '\n';
            }
        }
        line[i++] = c;
    }
    line[i] = '\0';
    return i;
}

void *handlerRequest(void *arg)
{
    int64_t sock = (int64_t)arg;
    char line[MAX];
    getLine(sock, line, sizeof(line));
    printf("%s", line);
    close(sock);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        usage(argv[0]);
        return 1;
    }

    int listen_sock = startp(atoi(argv[1]));
    while (1)
    {
        struct sockaddr_in client;
        socklen_t len = sizeof(client);
        int sock = accept(listen_sock, (struct sockaddr*)&client, &len);
        if (sock < 0)
        {
            perror("accept error");
            continue;
        }
        pthread_t tid;
        pthread_create(&tid, NULL, handlerRequest, (void*)sock);
    }
    return 0;
}
