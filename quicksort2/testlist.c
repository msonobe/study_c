# include <stdio.h>
# include <stdlib.h>
# include "list.h"
#include "listtools.h"

void print1(int num){
	printf("%d\n",num);
}

int randomInt(){
	int r = rand();
	return r%10;
}

int bigger(int num1, int num2){
	if(num2 > num1){
		return 1;
	}else{
		return 0;
	}
}

int smaller(int num1, int num2){
	if(num2 <= num1){
		return 1;
	}else{
		return 0;
	}
}

struct list* quicksort(struct list *li);

int main(void){

	srand(time(NULL));
	struct list *li1 = makelist(randomInt,5);
	struct list *li2 = makelist(randomInt,5);

	foreach(print1,li1);
	foreach(print1,li2);
	printf("\n");
	
	foreach(print1,concat(li1,li2));
	struct list *li3 = concat(li1,li2);
	printf("\n");

	foreach(print1,filter(bigger,5,li3));
	printf("\n");

	foreach(print1,filter(smaller,5,li3));
	printf("\n");

	foreach(print1,li3);
	printf("\n");

	foreach(print1,quicksort(li3));
	printf("\n");
	return 0;
}

struct list* quicksort(struct list *li){
	if(empty(li)){
		return li;
	}else{
		int h = head(li);
		struct list *t = tail(li);
		struct list *s = filter(smaller,h,t);
		struct list *b = filter(bigger,h,t);
		struct list *qss = quicksort(s);
		struct list *qsb = quicksort(b);
		return concat(qss,push(h,qsb));
	}
}
