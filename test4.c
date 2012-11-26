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
void list_insert(struct list *previous, struct list *add, struct list *next);
int get_data(struct list *list, int n);
/*void list_insert2(struct list *li, int n, int v);*/
struct list* array_list(int array[],int num );

int main(void){

	struct list *list1,*list2, *list3, *list4, *list5;
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

	list5 = add_list(3,list4);
	list_insert(list4,list5,list3);
	list_show(list4);

	int get_data_num = 0;
	get_data_num = get_data(list4,0);
	if(get_data_num == -1){
		printf ("値なし\n");
	}else{
		printf ("値→ %d\n",get_data_num);
	}

	int ary[5] = {5,2,4,1,3};
	int num_list = 5;
	printf ("%d\n",sizeof ary);
	struct list *listm =array_list(ary,num_list);
	list_show(listm);

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

void
list_insert(struct list *previous, struct list *add, struct list *next){
	struct list *pr = previous;
	struct list *ad = add;
	struct list *ne = next;
	pr->next = add;
	ad->next = ne;
}

int get_data(struct list *list, int n){
	struct list *next = list;
	int m = n;
	int i = 0;

	for(i =0; next != NULL; i++){ 
		if(i == m) break;
		next = next->next;
	}

	if (next != NULL) {
		return next->num;
	} else {
		return -1; 
	}
}

struct list * array_list(int array[],int num){
	
	/*struct list *li1,*li2, *li3, *li4, *li5;
	li1 = add_list(array[0],NULL);
	li2 = add_list(array[1],li1);
	li3 = add_list(array[2],li2);
	li4 = add_list(array[3],li3);
	li5 = add_list(array[4],li4);
	list_show(li5);*/
	int n =0;
	struct list *listn;
	printf("%d\n",sizeof array);
	for(n =num-1; n >= 0; n--){ 
		if(n == num-1){ 
			listn = add_list(array[n],NULL);
		}else{
			listn = add_list(array[n],listn);
		}
	}
	return listn;
}
