CC=gcc
CFLAGS=-Wall
LIBS=

OBJQ = rnum.o

%.o: src/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

rnum: $(OBJQ)
	$(CC) -o $@ $^ $(CLFAGS) $(LIBS)
	rm -f *.o

clean:
	rm -f rnum rnum.exe *.o
