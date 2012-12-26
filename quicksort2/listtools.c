# include "list.h"
# include "listtools.h"
# include <stdio.h>
# include <stdlib.h>


void foreach(void(*func)(int num),struct list *li){
	if(empty(li)){ 
		return;
	}else{
		int n = head(li);
		func(n);
		foreach(func,tail(li));
	}
}

void concat(struct list *li1, struct list *li2){
	li1->next = li2;
}

struct list* makelist(int(*func)(),int n){
	if(n == 0){
		return null();
	}
	return push(func(),makelist(func,n-1));
}
