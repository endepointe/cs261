CF = gcc -std=c99 -Wall -g -lm

all: ws22 ws24

ws22: ws22.o linkedList.o 
	$(CF) ws22.o linkedList.o -o ws22

ws23: ws23.o dynArray.o 
	$(CF) ws23.o dynArray.o -o ws23

ws24: ws23.o dynArray.o
	$(CF) ws24.o linkedList.o -o ws24

ws22.o: ws22.c
	$(CF) -c ws22.c

ws23.o: ws23.c
	$(CF) -c ws23.c

ws24.o: ws24.c 
	$(CF) -c ws24.c

############################



linkedList.o: linkedList.c
	$(CF) -c linkedList.c

dynArray.o: dynArray.c
	$(CF) -c dynArray.c

clean:
	rm *.o *.exe *.exe.* 
