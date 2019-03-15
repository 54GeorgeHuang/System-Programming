TARGET=shell

$(TARGET): Myshell.o error.o
	$(CC) -o $@ $^ 

Myshell.o: Myshell.c
error.o: error.c

clean:
	rm -f Myshell.o error.o $(TARGET)
