CC = gcc
CFLAGS = -g -Wall -std=c99
SP = spellChecker

all : tests $(SP)

tests : tests.o hashMap.o CuTest.o
	$(CC) $(CFLAGS) -o $@ $^

$(SP):  $(SP).o hashMap.o
	$(CC) $(CFLAGS) -o $@ $^

tests.o : tests.c CuTest.h hashMap.h

hashMap.o : hashMap.h hashMap.c

CuTest.o : CuTest.h CuTest.c

$(SP).o :  $(SP).c hashMap.h

memCheckTests :
	valgrind --tool=memcheck --leak-check=yes tests

memCheckSpellChecker :
	valgrind --tool=memcheck --leak-check=yes $(SP)

clean :
	-rm *.o
	-rm tests
	-rm spellChecker
	-rm sp
	-rm *.exe.stackdump
	-rm *.exe
