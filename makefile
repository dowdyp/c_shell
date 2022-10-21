CC=gcc

default: mshell

mshell: shell.o helper.o
	$(CC) -o shell shell.o helper.o

shell.o: shell.c
	$(CC) -c shell.c

helper.o: helper.c
	$(CC) -c helper.c

clean:
	$(RM) shell *.o
