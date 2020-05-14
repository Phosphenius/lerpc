CFLAGS += -Wall -Wextra -pedantic -Werror -g -O3 -std=c11
DESTDIR ?=
PREFIX ?= /usr/local
BINDIR ?= /bin

lerpc: 
lerpc.o: 

clean:
	-rm lerpc lerpc.o lerpc.1.gz
	
install: install-man lerpc LICENSE README.md
	install -D lerpc $(DESTDIR)$(PREFIX)$(BINDIR)/lerpc
	install -D LICENSE $(DESTDIR)$(PREFIX)/share/licenses/lerp/LICENSE
	install -D README.md $(DESTDIR)$(PREFIX)/share/doc/lerp/README.md

install-man: lerpc.1.gz
	install -d $(DESTDIR)$(PREFIX)/share/man/man1/
	install -m 644 $< $(DESTDIR)$(PREFIX)/share/man/man1/

lerpc.1.gz: lerpc.1
	gzip -f -k $<

.PHONY: clean install install-man lerpc.1.gz 
