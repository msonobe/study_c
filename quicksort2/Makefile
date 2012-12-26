testlist: list.o testlist.o listtools.o
	gcc -o testlist list.o testlist.o listtools.o

list.o: list.c list.h
	gcc -c list.c

testlist.o: testlist.c list.h
	gcc -c testlist.c

listtools.o: listtools.c listtools.h
	gcc -c listtools.c
