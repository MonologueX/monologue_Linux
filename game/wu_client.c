#include "wu_game.c"

void Game(int sock)
{
	wuziqi game_client, game_server;
	char map[ROW][COL];
	Init(map);
	Print(map);
	ssize_t s;
	while (1)
    {
		Play(map, &game_client);
		Print(map);
		write(sock, (void*)&game_client, sizeof(game_client));
		if (IsWin(map, BLACK_FLAG))
		{
            printf("BLACK(%c) is winer!!!\n", BLACK_FLAG);
            break;
        }
		s = read(sock, (void*)&game_server, sizeof(game_server));
        map[game_server.row][game_server.col] = WHITE_FLAG;
		if (s == 0)
        {
			printf("server quit\n");
			return;
		}
		Print(map);
		if (IsWin(map, WHITE_FLAG))
		{
            printf("WHITE(%c) is winer!!!\n", WHITE_FLAG);
            break;
        }
	}
}

int main(int argc,char*argv[])
{
	if (argc != 3)
    {
		printf("Usage: ./server [ip][port]");
		return 1;
	}
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd < 0)
    {
		printf("socket error\n");
		return 2;
	}
	struct sockaddr_in client;
	client.sin_family = AF_INET;
	client.sin_addr.s_addr = inet_addr(argv[1]);
	client.sin_port = htons(atoi(argv[2]));
	int ss = connect(fd, (const struct sockaddr*)&client, sizeof(client));
	if (ss < 0)
    {
		printf("connect error\n");
		return 3;
	}
	int num;
	while (1)
	{
        menu();
	    printf("please select: ");
	    scanf("%d", &num);
		if (num == 1)
        {
			Game(fd);
		}
        else if (num == 0)
        {
			break;
		}
	}
	close(fd);
}
