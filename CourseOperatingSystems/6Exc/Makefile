CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lrt

all: server client

server: server.o
	$(CC) $(CFLAGS) -o server server.o $(LDFLAGS)

client: client.o
	$(CC) $(CFLAGS) -o client client.o $(LDFLAGS)

server.o: server.c
	$(CC) $(CFLAGS) -c server.c

client.o: client.c
	$(CC) $(CFLAGS) -c client.c

clean:
	rm -f server client server.o client.o
