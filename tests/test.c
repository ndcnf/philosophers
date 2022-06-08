#include "test.h"

int	main()
{
	node	head;

	head.id = 15;
	head.next->next = malloc(sizeof(node));
	head.next->id = -2;
	head.next->next = NULL;

	printf("first : %d\n", head.id);
	printf("second : %d\n", head.next->id);
	free(head.next);
	return (0);
}
