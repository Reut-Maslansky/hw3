all: isort txtfind

isort: isort.c
	gcc -Wall -o isort isort.c

txtfind: txtfind.c
	gcc -Wall -o txtfind txtfind.c

clean:
	rm -f *.o txtfind isort
