lerpc: main.c
	gcc -o lerpc main.c -Wall -Werror

clean:
	rm lerpc
	
install:
	install -D lerpc $(DESTDIR)usr/bin/lerpc
