#include "lists.h"
/**
 * insert_node - function that inserts a node
 *
 * @head: head of the linked list.
 * @number: data of the node.
 *
 * Return: the address of the new node, or NULL if it failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current = *head, *prev;
	listint_t *new;

    if (!head)
		return (0);

	while (current && current->n <= number)
	{
		prev = current;
		current = current->next;
	}
	new = malloc(sizeof(listint_t));
	if (!new)
		return 0;
	new->n = number;
	new->next = current;
	prev->next = new;
	return (new);
}
