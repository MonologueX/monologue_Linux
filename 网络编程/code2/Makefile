.PHONY:
all:udp_serv udp_cli

udp_serv:udp_serv.c 
	gcc udp_serv.c -o udp_serv 
udp_cli:udp_cli.c 
	gcc udp_cli.c -o udp_cli 

.PHONY:clean
clean:
	rm -f udp_serv udp_cli
