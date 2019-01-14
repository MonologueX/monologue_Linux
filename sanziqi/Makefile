.PHONY:all 
all:san_cli san_serv

san_serv:san_serv.c 
	gcc san_serv.c -g -o san_serv 
san_cli:san_cli.c 
	gcc san_cli.c -g -o san_cli 

.PHONY:clean
clean:
	rm -f san_serv san_cli
