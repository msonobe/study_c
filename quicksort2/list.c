# include <stdio.h>
# include <stdlib.h>
# include "list.h"


struct list* null(){
	return NULL;
}

int empty(struct list *li){
	if(li == NULL){
		return 1;
	}else{
		return 0;
	}
}

struct list* push(int num,struct list *li){
	struct list *l = calloc(1,sizeof(struct list));
	l->num = num;
	l->next = li;
	return l;
}

int head(struct list *li){ 
	return li->num;
}

struct list* tail(struct list *li){
	return li->next;
}
