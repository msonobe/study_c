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

int main(void){

	srand(time(NULL));
	struct list *li1 = makelist(randomInt,5);
	struct list *li2 = makelist(randomInt,5);

	foreach(print1,li1);
	foreach(print1,li2);
	printf("\n");
	
	foreach(print1,concat(li1,li2));
	return 0;
}

