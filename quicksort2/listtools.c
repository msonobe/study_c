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

struct list* concat(struct list *li1, struct list *li2){
	if(empty(li1)){
		return li2;
	}else{
		return push(head(li1),concat(tail(li1),li2));
	}
}

struct list* makelist(int(*func)(),int n){
	if(n == 0){
		return null();
	}
	return push(func(),makelist(func,n-1));
}
