#include "lists.h"

/**
 * check_cycle -  checks if a singly linked list has a cycle in it.
 *
 * @list: head of the linked list.
 *
 * Return: 1 if there is a cycle, 0 otherwise.
 */
int check_cycle(listint_t *list)
{
	listint_t *fast = list, *slow = list;

	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return (1);
	}
	return (0);
}
