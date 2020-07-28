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
	listint_t *current = *head;
	listint_t *prev;
	listint_t *new;

    if (!head)
		return (NULL);
	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	new->n = number;
	if (!current || number < (*head)->n)
	{
		new->next = current;
		*head = new;
		return (*head);
	}

	while (current && current->n <= number)
	{
		prev = current;
		current = current->next;
	}

	new->next = current;
	prev->next = new;
	return (new);
}
