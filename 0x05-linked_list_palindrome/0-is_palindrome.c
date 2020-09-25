#include "lists.h"
/**
 * is_palindrome - checks if a linked list is palindrome.
 *
 * @head: head of linked list.
 *
 * Return: 1 if it is palindrome, 0 otherwise.
 */
int is_palindrome(listint_t **head)
{
	listint_t *current = *head, *first = *head;

	if (!*head)
		return (1);

	while (current && current->next)
		current = current->next;

	return (palindrome(first, current));
}
/**
 * palindrome - checks if an array is palindrome.
 *
 * @first: the first node to compare.
 * @last: the second node to compae.
 *
 * Return: 1 if palindrome, 0 if not.
 */
int palindrome(listint_t *first, listint_t *last)
{
	listint_t *current = first;

	if (first->n == last->n)
	{
		while (current->next && current->next != last)
			current = current->next;
		return (palindrome(first->next, current));
	}
	if (first == last || (first->next == last && first->n == last->n))
		return (0);
	return (1);
}
