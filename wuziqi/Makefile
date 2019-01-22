.PHONY:all
all:server client

server:server.c
	gcc server.c game.c game.h -o server
client:client.c
	gcc client.c game.c game.h -o client

.PHONY:clean 
clean:
	rm -f client server
