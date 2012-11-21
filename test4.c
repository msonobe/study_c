# include <stdio.h>
# include <stdlib.h>


struct list {
	int num;
	struct list *next;
};

struct list* add_list(int num, struct list *old);
int list_length(struct list *li);
int list_num(struct list *li, int num);
void list_show(struct list *li);

void print_atai(int n);
void print_value(int n);
void print_twice(int n);
void foreach(struct list *li, void fun(int));

int main(void){

	struct list *list1,*list2, *list3, *list4;
	int num = 0;
	int num2 = 0;

	list1 = add_list(5,NULL);
	list2 = add_list(4,list1);
	list3 = add_list(9,list2);
	list4 = add_list(2,list3);

	printf("%d(%p)\n",list4->num,list4->next);
	num = list_length(list4);
	printf("%d\n",num);
	num2 = list_num(list4, 8);
	list_show(list4);
	foreach(list4, print_atai);
	foreach(list4, print_value);
	foreach(list4, print_twice);

	return 0;
}

struct list* add_list(int num, struct list *old){

	struct list *new = calloc(1,sizeof(struct list));
	new->num = num;
	new->next = old;
	/*printf("test %s(%d)\n",name,num);*/

	return new;
}

int list_length(struct list *li){
	struct list *next = li;
	int i = 0;
	for(i =0; next != NULL; i++){ 
		next = next->next;
	}
	return i;
}

int list_num(struct list *li, int num){
	struct list *next = li;
	int i = 0;
	int n = num;
	for(i =0; next != NULL; i++){ 
		if(next->num == n){
			return i;
		}
		next = next->next;
	}
	return -1;
}

void print_atai(int n) { printf("値: %d\n", n); }
void print_value(int n) { printf("value: %d\n", n); }
void print_twice(int n) { printf("%d\n", n * 2); }

void
foreach(struct list *li, void fun(int))
{
	struct list *l = li;
	while (l != NULL) {
		fun(l->num);
		l = l->next;
	}
	return;
}

void list_show(struct list *li){
	struct list *next = li;
	while(next != NULL){ 
		printf("値%d\n",next->num);
		next = next->next;
	}
}
