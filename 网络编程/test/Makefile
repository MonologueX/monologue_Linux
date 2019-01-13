.PHONY:all
all:udp_serv udp_cli 

udp_serv:udp_serv.c 
	gcc udp_serv.c -o udp_serv 
udp_cli:udp_cli.cpp 
	g++ udp_cli.cpp -o udp_cli 

.PHONY:clean
clean:
	rm -f udp_serv udp_cli 
