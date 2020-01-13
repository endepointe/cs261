CF = gcc -Wall -g -std=c99 

default: a1 

a1: q0.o
	$(CF) q0.o -o a1 -lm

q0.o: q0.c
	$(CF) -c q0.c

clean:
	rm *.o

cleanall: clean
	rm a1 


