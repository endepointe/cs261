CF = gcc -std=c99 -Wall -g -lm

all: ws22

ws22: ws22.o 
	$(CF) ws22.o -o ws22

ws22.o: ws22.c
	$(CF) -c ws22.c

clean:
	rm *.o *.exe ws22
