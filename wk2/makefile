CF = gcc -Wall -g -std=c99 -lm

default: all 

all:
	$(CF) Q0.c -o Q0
	$(CF) Q1.c -o Q1

Q0: Q0.c
	$(CF) Q0.c -o Q0

Q1: Q1.c
	$(CF) Q1.c -o Q1 

clean:
	rm *.o

cleanall: clean
	rm a1 


