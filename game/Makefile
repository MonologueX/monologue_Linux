.PHONY:all
all:server client
server:wu_server.c
	gcc wu_server.c -o server
client:wu_client.c
	gcc wu_client.c -o client
.PHONY:clean
clean:
	rm -f server client
