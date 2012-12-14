# include <stdio.h>
# include <stdlib.h>
# include "list.h"

struct mems* unshift(int num, struct mems *me){
	struct mems *new = calloc(1,sizeof(struct mems));
	new->num = num;
	new->next = me;

	return new;
}

void foreach(void(*func)(int num),struct mems *mem){
	while(mem != NULL){
		func(mem->num);
		mem = mem->next;
	}
}

