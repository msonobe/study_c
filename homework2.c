#include <stdio.h>

int main(void){
	int ary[5];
	int i = 0;
	for(i =0; i<6; i++){
		ary[i] = i+1;
		printf("%d\n",ary[i]);
	}

	for(i =5; i>=0; i--){
		ary[i+1] = ary[i];
		printf("%d\n",ary[i+1]);
	}
}
