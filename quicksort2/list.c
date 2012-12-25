# include <stdio.h>
# include <stdlib.h>
# include "list.h"


struct list* null(){
	struct list *li = calloc(1,sizeof(struct list));
	li->next = NULL;
	return li;
}

int empty(struct list *li){
	if(li->next == NULL){
		return 1;
	}else{
		return 0;
	}
}

struct list* push(struct list *li, int num){
	li->num = num;
	li->next = li;
	return li;
}

struct list* head(int ary[]){ 
		
}
