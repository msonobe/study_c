# include <stdlib.h>
# include <stdio.h>
# include "list.h"

void print1(int num){
	printf("%d\n",num);
}

int main(void){

	struct list *li;
	li = new_list();
	unshift(li,5); 
	unshift(li,3); 
	unshift(li,7); 
	unshift(li,4); 
	unshift(li,6); 
	foreach(print1,li);
	printf("\n");

	push(li,9); 
	foreach(print1,li);
	return 0;
}
