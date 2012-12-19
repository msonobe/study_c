# include <stdio.h>
# include <stdlib.h>
# include "list.h"

struct mems* unshift_mems(int num, struct mems *me){
	struct mems *new = calloc(1,sizeof(struct mems));
	new->num = num;
	new->next = me;

	return new;
}

void foreach_mems(void(*func)(int num),struct mems *mem){
	while(mem != NULL){
		func(mem->num);
		mem = mem->next;
	}
}

void foreach(void(*func)(int num),struct list *li){
	struct mems *mem = li->head;
	while(mem != NULL){
		func(mem->num);
		mem = mem->next;
	}
}

struct list* new_list(){
	struct list *li = calloc(1,sizeof(struct list));
	li->head = NULL;
	li->last = NULL;
	return li;
}

void unshift(struct list *li, int nums){
	int ret_empty = 0;
	ret_empty = empty(li);
	struct mems *me;
	me = unshift_mems(nums,li->head);
	li->head = me;
	if(ret_empty != 0){
		li->last = me;
	}
}

int empty(struct list *li){
	if((li->head == NULL)&&(li->last == NULL)){
		return 1;
	}else{
		return 0;
	}
}

void push(struct list *li, int num){
	int ret_empty = 0;
	ret_empty = empty(li);
	
	struct mems *new = calloc(1,sizeof(struct mems));
	new->num = num;
	new->next = NULL;
	li->last->next = new;
	li->last = new;
	if(ret_empty != 0){
		li->head = new;
	}
}
