#include"game.c"

void Game(int sock)
{
	game game_client;
	game game_server;
	ssize_t s;
	while (1)
    {
        char map[ROW][COL];
	    Init(map);
	    Print(map);
	    while (1)
	    {
	    	int result;
	    	int nums;
	    	for (nums = 0; nums < 225; nums++)
	    	{
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
	    	        write(sock, (void*)&game_client, sizeof(game_client));
	    		}
	    		Print(map);
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
	    	    s = read(sock, (void*)&game_server, sizeof(game_server));
	    	    if (s == 0)
                {
	    	    	printf("server quit\n");
	    	    	return;
	    	    }
            }
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
	menu();
	while (1)
	{
		int choice;
		scanf("%d", &choice);
		if (0 == choice)
			break;
		else if (1 == choice)
	        Game(fd);
		else
			printf("输入错误，请重新输入：");
	}
	close(fd);
    return 0;
}
