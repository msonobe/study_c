# include <stdio.h>

struct mountain{
	char *name;
	int height;
};

int main(void){

	/*struct mountain *akagi, *haruna, *myougi, *asama;*/

	struct mountain akagi = {"赤城",1827};
	struct mountain haruna = {"榛名",1449};
	struct mountain myougi = {"妙義",1103};
	struct mountain asama = {"浅間",2568};

	/*akagi.name = "赤城";
	akagi.height = 1827;
	haruna.name = "榛名"
	haruna.height = 1449;
	myougi.name = "妙義"
	myougi.height = 1103;
	asama.name = "浅間"
	asama.height = 2568;*/

	printf("%s(%d)\n",akagi.name,akagi.height);
	printf("%s(%d)\n",haruna.name,haruna.height);
	printf("%s(%d)\n",myougi.name,myougi.height);
	printf("%s(%d)\n",asama.name,asama.height);
	return 0;
}
