all: buffsize100 buffsize4096 buffsize8192 buffsize16384 fsync_buffsize4096
CC:=gcc

buffsize100: obj100.o error.o
	$(CC) -o $@ $^
buffsize4096: obj4096.o error.o
	$(CC) -o $@ $^
buffsize8192: obj8192.o error.o
	$(CC) -o $@ $^
buffsize16384: obj16384.o error.o
	$(CC) -o $@ $^

fsync_buffsize4096: objfsync4096.o error.o
	$(CC) -o $@ $^

obj100.o: source.c
	$(CC) -Wall -D BUFFSIZE=100 -c -o $@ $^
obj4096.o: source.c
	$(CC) -Wall -D BUFFSIZE=4096 -c -o $@ $^
obj8192.o: source.c
	$(CC) -Wall -D BUFFSIZE=8192 -c -o $@ $^
obj16384.o: source.c
	$(CC) -Wall -D BUFFSIZE=16384 -c -o $@ $^

objfsync4096.o: source_fsync.c
	$(CC) -Wall -D BUFFSIZE=4096 -c -o $@ $^

error.o: error.c
	$(CC) -Wall -c $^

.PHONY: clean
clean:
	rm *.o 
