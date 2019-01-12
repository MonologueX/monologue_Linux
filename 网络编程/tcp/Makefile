.PHONY:all
all:tcp_serv tcp_cli

tcp_serv:tcp_serv.c 
	gcc tcp_serv.c -o tcp_serv 
tcp_cli:tcp_cli.c 
	gcc tcp_cli.c -o tcp_cli
.PHONY:clean
clean:
	rm -f tcp_serv tcp_cli
