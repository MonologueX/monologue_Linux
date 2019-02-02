#include"game.c"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>

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
		game game_server, game_client;
		menu();
        char map[ROW][COL];
		int result;
		int nums;
		Init(map);
		Print(map);
		for (nums = 0; nums < 225; nums++)
		{
			s = read(client_sock,(void*)&game_client,sizeof(game_client));
			if (s == 0)
            {
				printf("client quit!\n");
				close(client_sock);
				return 0;
            }
			if (player == BLACK)
			{
				//玩家下子
				printf("please white(%c) play\n", WHITE_FLAG);
				player = WHITE;
				result = Play(map, &game_client);
				if (!result)
					break;
			}
			else
			{
				//电脑下子
				player = BLACK;
				ComputerPlay(map, &game_server);
			}
			Print(map);
			write(client_sock, (void*)&game_server, sizeof(game_server));
			if (IsWin(map))
			{
				if (player == WHITE)
				{
					printf("WHITE(%c) is winner.\n", WHITE_FLAG);
				}
				else
				{
					printf("BLACK(%c) is winner.\n", BLACK_FLAG);
				}
				break;
			}
		}
	}
	close(fd);
}
