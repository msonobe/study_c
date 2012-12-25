# include <stdio.h>
# include <stdlib.h>
# include "list.h"

int main(void){

	struct list *li = push(4,push(3,null()));
	int num = head(li);
	printf("%d\n",num);

	return 0;
}
