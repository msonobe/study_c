testlist: list.o testlist.o
	gcc -o testlist list.o testlist.o

list.o: list.c list.h
	gcc -c list.c

testlist.o: testlist.c list.h
	gcc -c testlist.c	
