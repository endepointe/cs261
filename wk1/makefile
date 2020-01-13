CF = gcc -Wall -g -std=c99 

default: triangle

triangle: triangle.o
	$(CF) triangle.o -o triangle -lm

triangle.o: triangle.c
	$(CF) -c triangle.c

clean:
	rm *.o

cleanall: clean
	rm triangle


