#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_t{
		const char *str;
		struct node_t *next;
	} node_t;

void FreeList(node_t **ptr);
void RemoveNode(node_t **ptr, const char *str);
void PrintNodes(node_t **ptr);
void CreateNode(node_t **ptr, const char *str); 

/*
The allocator is defaulted to glibc's general purpose allocator, to change it to your own custom allocator simply change malloc_fc and free_fn
*/	
#ifndef malloc_fn
#define malloc_fn(X) malloc(X)
#endif

#ifndef free_fn
#define free_fn(X) free(X)
#endif