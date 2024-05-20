CC ?= cc
CFLAGS ?=
LDFLAGS ?=
CPPFLAGS ?=
DESTDIR ?= /usr/local
BINDIR ?= $(DESTDIR)/bin
MANDIR ?= $(DESTDIR)/share/man

rnum: rnum.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $^ $<

clean:
	rm -f rnum

install:
	install -m755 rnum $(BINDIR)
	install -m644 rnum.1 $(MANDIR)/man1

.PHONY: clean install
