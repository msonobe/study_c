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
int comp_tree(struct tree *tr, int n);

int main(void){
	struct tree *tree1,*tree2,*tree3,*tree4,*tree5,*tree6,*tree7;
	tree1 = make_tree(3);
	tree2 = make_tree(5);
	tree3 = make_tree(8);
	tree4 = make_tree(12);
	tree5 = make_tree(14);
	tree6 = make_tree(18);
	tree7 = make_tree(20);

	add_node(tree4,tree6,tree2);
	add_node(tree2,tree3,tree1);
	add_node(tree6,tree7,tree5);
	add_node(tree1,NULL,NULL);
	add_node(tree3,NULL,NULL);
	add_node(tree5,NULL,NULL);
	add_node(tree7,NULL,NULL);

	show_tree(tree4);

	int test1 = 24;
	int test2 = 14;
	int m = comp_tree(tree4, test1);
	if(m > 0){
		printf("%d:あり\n",test1);
	}else{
		printf("%d:なし\n",test1);
	}

	m = 0;
	m = comp_tree(tree4, test2);
	if(m > 0){
		printf("%d:あり\n",test2);
	}else{
		printf("%d:なし\n",test2);
	}
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
	if(tr == NULL){
		return;
	}

	printf("tree:%d\n",tr->num);

	show_tree(tr->small);
	show_tree(tr->big);
}

int comp_tree(struct tree *tr, int n){
	if(tr == NULL){
		return 0;
	}

	if(tr->num == n){
		return 1;
	}else if(tr->num > n){
		comp_tree(tr->small,n);
	}else if(tr->num < n){
		comp_tree(tr->big,n);
	}
}
