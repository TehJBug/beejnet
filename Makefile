all: showip server server_127_0_0_1 server_192_168_1_200 server_0_0_0_0 client

showip: showip.c
	gcc -g -o showip showip.c

server: server.c
	       gcc -g -o server server.c

server_127_0_0_1: server_127_0_0_1.c
	gcc -g -o server_127_0_0_1 server_127_0_0_1.c

server_192_168_1_200: server_192_168_1_200.c
	gcc -g -o server_192_168_1_200 server_192_168_1_200.c

server_0_0_0_0: server_0_0_0_0.c
	gcc -g -o server_0_0_0_0 server_0_0_0_0.c

client: client.c
	       gcc -g -o client client.c

clean:
	rm showip server server_127_0_0_1 server_192_168_1_200 server_0_0_0_0 client
