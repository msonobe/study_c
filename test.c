#include <stdio.h>
#include <stdlib.h>

struct person{
	char *name;
	int age;
};

void printperson(struct person p);
struct person* make_person(char *name, int age);

int main(void){

	struct person *somebody, *dareka;

	somebody = make_person("john", 30);
	dareka = make_person("太郎", 32);
	printperson(*somebody);
	printperson(*dareka);

	return 0;
}

void printperson(struct person p){

	printf("%s(%d)\n",p.name,p.age);
}

struct person*
make_person(char *name, int age) {
	struct person *p = calloc(1, sizeof(struct person));
	p->name = name;
	p->age = age;
//	printperson(p);

	return p;
}
