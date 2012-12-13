# include <stdio.h>
# include <stdlib.h>

int rand_ary(int max_num, int ary_num, int ary[]);
int main(void){
	int max_num = 99;
	int ary_num = 10;
	int ary[10];
	int m = 0;
	m = rand_ary(max_num, ary_num, ary);
	int n = 0;
	for(n = 0; n< ary_num; n++){
		printf("%d\n",ary[n]);
	}
}

int rand_ary(int max_num, int ary_num, int ary[]){
	int n = 0;
	srand((unsigned)time(NULL));
	for(n = 0; n<= ary_num; n++){
		ary[n] = rand()%max_num+1;
	}
	return 0;
}
