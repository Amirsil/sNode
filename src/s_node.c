#include "s_node.h"

void CreateNode(node_t **ptr, const char *str)
{
	node_t *newptr = (node_t *)malloc_fn(sizeof(node_t));
	if (newptr == NULL) {
		printf("Failed to malloc_fn memory in the heap :(");
		return;
	}

	*newptr = *ptr \
				? (node_t){str, *ptr} \
				: (node_t){str, NULL};
	
	printf("Added \"%s\" (%p)\n", newptr -> str, newptr);
	*ptr = newptr;
}


void RemoveNode(node_t **ptr, const char *str)
{
	node_t *node = *ptr;
	if (!node)
		return;
	
	if (!strcmp(node -> str, str))
	{
		if (!(node -> next)) *ptr = NULL;
		else  *ptr = node -> next;
		printf("Removed \"%s\" (%p)\n", node -> str, node);
		free(node);
		return;
	}

	node_t *nextptr;	
	for (node_t *node = *ptr ; node -> next ; node = node -> next)
	{
		nextptr = node -> next;
		if (!strcmp(nextptr -> str, str))
		{
			if (node -> next -> next)
				node -> next = node -> next -> next;
			else
				node -> next = NULL;
			printf("Removed \"%s\" (%p)\n", nextptr -> str, nextptr);
			free_fn(nextptr);
			return;
		}

	}
	printf("\"%s\" is not in the list, therefore it cannot be removed.", str);
}

void PrintNodes(node_t **ptr)
{
	printf("[");
	for (node_t *node = *ptr; node ; node = node -> next) printf("\"%s\" -> ", node -> str);
	printf("NULL]\n");
}

void FreeList(node_t **ptr)
{
	node_t tmp;
	node_t *node = *ptr;
	while(node)
	{
		tmp = *node;
		printf("Freed \"%s\" (%p) \n", node -> str, ptr);
		free_fn(node);
		node = tmp.next;
	}
}

