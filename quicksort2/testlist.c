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
	return 0;
}

