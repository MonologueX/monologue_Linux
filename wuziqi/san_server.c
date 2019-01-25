#include"san_game.h"

int main(int argc, char*argv[])
{
	if (argc != 3)
    {
		printf("Usage: ./server [ip] [port]\n");
		return 1;
	}
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd < 0)
    {
		printf("socket error\n");
		return 2;
	}
	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_addr.s_addr = inet_addr(argv[1]);
	local.sin_port = htons(atoi(argv[2]));
	int ret = bind(fd, (const struct sockaddr*)&local, sizeof(local));
	if (ret < 0)
    {
		printf("bind error\n");
		return 3;
	}
	ret = listen(fd, 5);
	if (ret < 0)
    {
		printf("listen error\n");
		return 4;
	}
	while (1)
    {
		struct sockaddr_in client;
		socklen_t len;
		int client_sock = accept(fd, (struct sockaddr*)&client, &len);
		if (client_sock < 0)
        {
			continue;
		}
		ssize_t s;
		sanziqi sanziqi_server, point_client;
		int array[ROW][COL];
		Init(array);
		int x, y;
		while (1)
        {
			s = read(client_sock,(void*)&point_client,sizeof(point_client));
			if (s == 0)
            {
				printf("client quit!\n");
				close(client_sock);
				return 0;
			}
			PlayMove(array, &point_client);
			Print(array);
			if (IsWin(array, &point_client) == '*')
			{
				printf("client win!\n");
				break;
			}
            else if (IsWin(array, &point_client) == 'p')
            {
				printf("equal!\n");
				break;
			}
			CmputerMove(array, &sanziqi_server);
			Print(array);
			write(client_sock, (void*)&sanziqi_server, sizeof(sanziqi_server));
			if (IsWin(array, &point_client) == '#')
            {
				printf("you win!\n");
				break;
			}
            else if (IsWin(array , &point_client) == 'p')
            {
				printf("equal! \n");
				break;
			}
		}
	}
	close(fd);
}
