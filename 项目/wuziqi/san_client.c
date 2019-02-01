#include "san_game.c"

void Game(int sock)
{
    sanziqi *san;
	Init(&san);
	Print(san);
	ssize_t s;
	while (1)
    {
		PlayMove(&san);
		Print(san);
		write(sock, (void*)&san, sizeof(san));
		if (IsWin(san) == 1)
		{
			printf("client win!\n");
			break;
		}
        else if (IsWin(san) == 2)
        {
			printf("equal!\n");
			break;
		}
		s = read(sock, (void*)&san, sizeof(san));
		if (s == 0)
        {
			printf("server quit\n");
			return;
		}
		ComputerMove(&san);
		Print(san);
		if (IsWin(san) == 1)
		{
			printf("client win!\n");
			break;
		}
        else if (IsWin(san) == 2)
        {
			printf("equal!\n");
			break;
		}
	}
}

int main(int argc, char*argv[])
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
	if(ss < 0)
    {
		printf("connect error\n");
		return 3;
	}
    Menu1();
	int num;
	while (1)
	{
		scanf("%d", &num);
		if(num == 1)
        {
			Game(fd);
		}
        else if (num == 0)
        {
			break;
		}
        else
        {
            Menu1();
			sleep(2);
		}
	}
	close(fd);
}
