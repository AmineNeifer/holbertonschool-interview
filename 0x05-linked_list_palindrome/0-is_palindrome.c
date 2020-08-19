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
	int size, i, *array;
	listint_t *current = *head;

	if (!*head)
		return (1);

	size = size_list(head);
	array = malloc(sizeof(int) * size);

	if (!array)
		return (0);

	for (i = 0; i < size; i++)
	{
		array[i] = current->n;
		current = current->next;
	}
	return (palindrome(array, size));
}
/**
 * size_list - counts the length of linked list.
 *
 * @head: head of linked list.
 *
 * Return: number of nodes of linked list.
 */
int size_list(listint_t **head)
{
	listint_t *current = *head;
	int size = 0;

	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}
/**
 * palindrome - checks if an array is palindrome.
 *
 * @array: int array.
 * @size: array size;
 *
 * Return: 1 if palindrome, 0 if not.
 */
int palindrome(int *array, int size)
{
	int i;

	for (i = 0; i < size / 2; i++)
		if (array[i] != array[size - i - 1])
			return (0);
	return (1);
}
