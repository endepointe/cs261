CF = gcc -Wall -g -std=c99 -lm

default: all 

all:
	$(CF) q0.c -o q0
	$(CF) q1.c -o q1

q0: q0.c
	$(CF) q0.c -o q0

q1: q1.c
	$(CF) q1.c -o q1 

clean:
	rm *.o *.exe

