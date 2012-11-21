# include <stdio.h>
# include <stdlib.h>


struct mountain {
	char *name;
	int height;
};

struct mountain* set_mountain(char *name, int num);

int main(void){

	struct mountain *akagi,*haruna,*myougi,*asama;

	akagi = set_mountain("赤城",1827);
	haruna = set_mountain("榛名",1449);
	myougi = set_mountain("妙義",1103);
	asama = set_mountain("浅間",2568);

	printf("%s(%d)\n",akagi->name,akagi->height);
	printf("%s(%d)\n",haruna->name,haruna->height);
	printf("%s(%d)\n",myougi->name,myougi->height);
	printf("%s(%d)\n",asama->name,asama->height);

	return 0;
}

struct mountain* set_mountain(char *name, int num){

	struct mountain *mo = calloc(1,sizeof(struct mountain));
	mo->name = name;
	mo->height = num;
	/*printf("test %s(%d)\n",name,num);*/

	return mo;
}
