# include <stdio.h>
# include <stdlib.h>

struct chimei{
	char *name;
	struct chimei *next;
	struct chimei *previous;
};

struct chimei* make_list(char *name,struct chimei *next);
void add_list(struct chimei *chi, char *name, int num);
void show_prevlist(struct chimei *chi, int num);

int main(void){
	char *array_chimei[5] = {"東京","新横浜","熱海","浜松","名古屋"};
	struct chimei *tokyo,*shinyokohama,*atami,*hamamatu,*nagoya;

	tokyo = make_list(array_chimei[0], NULL);
	shinyokohama = make_list(array_chimei[1], tokyo);
	atami = make_list(array_chimei[2], shinyokohama);
	hamamatu = make_list(array_chimei[3], atami);
	nagoya = make_list(array_chimei[4], hamamatu);
	show_prevlist(tokyo, 5);

	add_list(nagoya, "静岡", 1);
	show_prevlist(tokyo, 6);

	return 0;
}

struct chimei* make_list(char *name,struct chimei *next){
	struct chimei *new = calloc(1,sizeof(struct chimei));
	new->name = name;
	new->next = next;
	if(next != NULL){
		next->previous = new;
	}
	return new;
}

void add_list(struct chimei *chi, char *name, int num){
	struct chimei *shizuoka;
	int j = 0;
	for(j = 0; j < num ; j++){
		chi = chi->next;
	}
	struct chimei *chi2 = chi->next;
	shizuoka = make_list(name, NULL);
	shizuoka->next = chi2;
	shizuoka->previous = chi;
	chi->next = shizuoka;
	chi2->previous = shizuoka;
}

void show_prevlist(struct chimei *chi, int num){
	int i = 0;
	for(i = 0; i < num; i++){
		printf("地名:%s\n",chi->name);
		chi = chi->previous;
	}
	printf("\n");
}
