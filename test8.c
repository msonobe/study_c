# include <stdio.h>

int calc_add(int num);
int calc_add2(int num);

int main(void){
	int num = 10;
	int l = 0;
	int o = 0;
	l = calc_add(num);
	printf("%d\n",l);

	o = calc_add2(10);
	printf("%d\n",o);

	return 0;
}

int calc_add(int num){
	int n = 0;
	int m = 0;
	for(n = 1; n <= num; n++){
		m = m + n;
	}
	return m;
}

int calc_add2(int num){
	if(num == 0){
		return 0;
	}
	else{
		return num+calc_add2(num-1);
	}
}
