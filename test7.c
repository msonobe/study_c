# include <stdio.h>
# include <stdlib.h>

struct tree{
	int num;
	struct tree *small;
	struct tree *big;
};

struct tree* make_tree(int num);
void add_node(struct tree *tr, struct tree *trbig, struct tree *trsmall);
void show_tree(struct tree *tr);

int main(void){
	struct tree *tree1,*tree2,*tree3,*tree4,*tree5,*tree6,*tree7;
	tree1 = make_tree(1);
	tree2 = make_tree(2);
	tree3 = make_tree(3);
	tree4 = make_tree(4);
	tree5 = make_tree(5);
	tree6 = make_tree(6);
	tree7 = make_tree(7);

	add_node(tree4,tree6,tree2);
	add_node(tree2,tree3,tree1);
	add_node(tree6,tree7,tree5);
	add_node(tree1,NULL,NULL);
	add_node(tree3,NULL,NULL);
	add_node(tree5,NULL,NULL);
	add_node(tree7,NULL,NULL);

	show_tree(tree4);

	return 0;
}

struct tree* make_tree(int num){
	struct tree *new = calloc(1,sizeof(struct tree));
	new->num = num;
	new->small = NULL;
	new->big = NULL;
	return new;
}

void add_node(struct tree *tr, struct tree *trbig, struct tree *trsmall){
	tr->big = trbig;
	tr->small = trsmall;
}

void show_tree(struct tree *tr){
	struct tree *trsmall = tr;
	struct tree *trbig = tr;
	printf("tree:%d\n",tr->num);
	while(tr->big != NULL){
		tr = tr->big;
		printf("treebig:%d\n",tr->num);
	}
	while(trsmall->small != NULL){
		trsmall = trsmall->small;
		printf("treesmall:%d\n",trsmall->num);
	}
}
