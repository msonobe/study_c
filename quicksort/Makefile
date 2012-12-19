quicksort: list.o quicksort.o
	gcc list.o quicksort.o -o quicksort

list.o: list.c list.h
	gcc -c list.c

quicksort.o: quicksort.c list.h
	gcc -c quicksort.c
