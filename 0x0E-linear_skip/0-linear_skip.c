#include "search.h"
/**
 *
 *
 *
 *
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{

	size_t idx, idx_x;
	skiplist_t *current = list, *express;
	
	if (!list)
		return NULL;
	while(current)
	{
		if (current->express)
			express = current->express;
		else
		{
			express = current;
			while (express && express->next)
				express = express->next;
			idx = current->index;
            idx_x = express->index;
			printf("Value found between indexes [%lu] and [%lu]\n", idx, idx_x);
			return search(current, value);
			
		}
		printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
		if (express->n > value)
		{
			idx = current->index;
			idx_x = express->index;
			printf("Value found between indexes [%lu] and [%lu]\n", idx, idx_x);
			return (search(current, value));
		}
		if (current->express)
			current = current->express;
		else
			break;
	}
	return (NULL);
}

skiplist_t *search(skiplist_t *list, int value)
{
	skiplist_t *c;

	for(c = list; c; c= c->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", c->index, c->n);
		if (c->n == value)
			return (c);
	}
	return (NULL);
}
