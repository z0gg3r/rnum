rnum: src/rnum.c
	mkdir -p bin 
	gcc -o bin/rnum src/rnum.c -g

clean:
	rm -f bin/rnum

install: bin/rnum
	cp bin/rnum /bin/rnum

.PHONY: clean, install
