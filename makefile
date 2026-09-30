CC = gcc
CFLAGS = -I.

output: main.o matrix-utils.o penguinn-utils.o
	$(CC) $(CFLAGS) -o output.out *.o
	./output.out

debug: main.o matrix-utils.o penguinn-utils.o
	$(CC) $(CFLAGS) -g -o output.out *.o
	gdb ./output.out

clean:
	rm -f output main.o matrix-utils.o penguinn-utils.o
