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

	/* ループで作成できていない*/
	tokyo = make_list(array_chimei[0], NULL);
	shinyokohama = make_list(array_chimei[1], tokyo);
	atami = make_list(array_chimei[2], shinyokohama);
	hamamatu = make_list(array_chimei[3], atami);
	nagoya = make_list(array_chimei[4], hamamatu);
	show_list(nagoya,5);

	/* 指定した番号から1つずれてしまう*/
	add_list(nagoya, 1, "静岡");
	show_list(nagoya, 6);

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
	shizuoka = make_list(addname, chi);
	shizuoka->next = chi->next;
	chi->next = shizuoka;
}
