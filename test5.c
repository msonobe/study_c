# include <stdio.h>
# include <stdlib.h>

struct chimei{
	char *name;
	struct chimei *next;
};

struct chimei* make_list(char *na, struct chimei *chi);
void show_list(struct chimei *chi, int num);
void add_list(struct chimei *chi, int addnum, char *addname);

int main(void){
	char *array_chimei[5] = {"東京","新横浜","熱海","浜松","名古屋"};
	struct chimei *tokyo,*shinyokohama,*atami,*hamamatu,*nagoya;

	struct chimei *chi =NULL;
	int i = 0;
	for(i =0; i <5; i++){
		chi = make_list(array_chimei[i], chi);
	}
	show_list(chi,5);

	add_list(chi, 1, "静岡");
	show_list(chi, 6);

	return 0;
}

struct chimei* make_list(char *na, struct chimei *chi){
	struct chimei *new = calloc(1,sizeof(struct chimei));
	new->name = na;
	new->next = chi;

	return new;
}

void show_list(struct chimei *chi, int num){
	for(num; num>0; num--){
		printf("地名:%s\n",chi->name);
		chi = chi->next;
	}
	printf("\n");
}

void add_list(struct chimei *chi, int addnum, char *addname){
	int num = 0;
	for(num = 0; num<addnum; num++){
		chi = chi->next;
	}
	struct chimei *shizuoka;
	shizuoka = make_list(addname, NULL);
	shizuoka->next = chi->next;
	chi->next = shizuoka;
}
