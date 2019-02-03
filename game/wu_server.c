#include "wu_game.c"

int main(int argc, char*argv[])
{
	if(argc != 3)
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
	char map[ROW][COL];
	while(1)
    {
		struct sockaddr_in client;
		socklen_t len = sizeof(client);
		int client_sock = accept(fd, (struct sockaddr*)&client, &len);
		if (client_sock < 0)
        {
			continue;
		}
		ssize_t s;
		wuziqi game_server, game_client;
		Init(map);
		while (1)
        {
			s = read(client_sock, (void*)&game_client, sizeof(game_client));
			if (s == 0)
            {
				printf("client quit!\n");
				close(client_sock);
                break;
			}
            map[game_client.row][game_client.col] = BLACK_FLAG;
			Print(map);
			if (IsWin(map))
			{
                printf("BLACK(%c) is winer!!!\n", BLACK_FLAG);
                break;
            }

			ComputerPlay(map, &game_server);
		    Print(map);
		    write(client_sock, (void*)&game_server, sizeof(game_server));
		    if (IsWin(map))
		    {
                printf("WHITE(%c) is winer!!!\n", WHITE_FLAG);
                break;
            }
        }
	}
	close(fd);
}
