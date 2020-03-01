rnum: src/rnum.c src/rnum.h
	mkdir bin -p
	gcc -o bin/rnum src/rnum.c

clean:
	rm -f bin/rnum

install: bin/rnum
	cp bin/rnum /bin/rnum

.PHONY: clean, install
