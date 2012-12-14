# include <stdlib.h>
# include <stdio.h>
# include "list.h"

void print1(int num){
	printf("%d\n",num);
}

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
	
	foreach(print1,mem7);
	return;
}
