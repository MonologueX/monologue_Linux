.PHONY:all
all:server client

server:server.c
	gcc server.c -g -o server
client:client.c
	gcc client.c -g -o client

.PHONY:clean 
clean:
	rm -f client server
