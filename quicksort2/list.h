
struct list{
	int num;
	struct list *next;
};

struct list* null();
int empty(struct list *li);
struct list* push(int num,struct list *li);
int head(struct list *li);
struct list* tail(struct list *li);
