lerpc: main.c
	gcc -o lerpc main.c -Wall -Werror

clean:
	rm lerpc
	
install:
	install lerpc /usr/bin
