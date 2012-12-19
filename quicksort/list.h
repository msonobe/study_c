
struct mems {
	int num;
	struct mems *next;
};

struct list {
	struct mems *head;
	struct mems *last;
};

void foreach(void(*func)(int num),struct list *li);
struct list* new_list();
void unshift(struct list *li, int nums);
void push(struct list *li, int nums);
