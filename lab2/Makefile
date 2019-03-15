TARGET=shell

$(TARGET): fig3_4.o error.o
	$(CC) -o $@ $^ 

fig3_4.o: fig3_4.c
error.o: error.c

clean:
	rm -f fig3_4.o error.o $(TARGET)
