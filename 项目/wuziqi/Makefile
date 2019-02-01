.PHONY:all
all:san_server san_client

server:server.c
	gcc san_server.c -o server
client:client.c
	gcc san_client.c -o client

.PHONY:clean 
clean:
	rm -f san_client san_server
