

void foreach(void(*func)(int num),struct list *li);
struct list* concat(struct list *li1, struct list *li2);
struct list* makelist(int(*func)(),int n);
struct list* filter(int(*func)(int num1,int num2),int num3, struct list *li);
