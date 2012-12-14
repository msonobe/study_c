
struct mems {
	int num;
	struct mems *next;
};

struct list {
	int num;
	struct mems *next;
	struct mems *previous;
};

struct mems* unshift(int num, struct mems *me);
void foreach(void(*func)(int num),struct mems *mem);
