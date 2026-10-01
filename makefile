CC = gcc
LDLIBS = -lm

output.out:
	$(CC) *.c $(LDLIBS) -o output.out
	./output.out

debug:
	$(CC) -g *.c $(LDLIBS) -o output.out
	gdb ./output.out

clean:
	rm -f *.out *.o
