# include <stdio.h>
# include <stdlib.h>

struct mems {
	int num;
	struct mems *next;
};

struct mems* unshift(int num, struct mems *me);
void printlist(struct mems *me);
void foreach(void(*func)(int num),struct mems *mem);
void print1(int num);

int main(void){

	int array_num[7] = {5,1,4,2,3,7,6};
	struct mems *mem1, *mem2, *mem3, *mem4, *mem5, *mem6, *mem7;
	mem1 = unshift(array_num[0], NULL);
	mem2 = unshift(array_num[1], mem1);
	mem3 = unshift(array_num[2], mem2);
	mem4 = unshift(array_num[3], mem3);
	mem5 = unshift(array_num[4], mem4);
	mem6 = unshift(array_num[5], mem5);
	mem7 = unshift(array_num[6], mem6);
	
	printlist(mem7);

	foreach(print1,mem7);
	return;
}

struct mems* unshift(int num, struct mems *me){
	struct mems *new = calloc(1,sizeof(struct mems));
	new->num = num;
	new->next = me;

	return new;
}

void printlist(struct mems *me){
	while(me != NULL){
		printf("num:%d\n",me->num);
		me = me->next;
	}
}

void foreach(void(*func)(int num),struct mems *mem){
	while(mem != NULL){
		func(mem->num);
		mem = mem->next;
	}
}

void print1(int num){
	printf("%d\n",num);
}
