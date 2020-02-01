CF = gcc -std=c99 -Wall -g -lm

all: ws22

ws22: ws22.o linkedList.o 
	$(CF) ws22.o linkedList.o -o ws22

ws22.o: ws22.c
	$(CF) -c ws22.c

linkedList.o: linkedList.c
	$(CF) -c linkedList.c

clean:
	rm *.o *.exe *.exe.* ws22
