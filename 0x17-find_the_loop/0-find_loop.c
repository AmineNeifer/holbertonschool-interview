#include <stdio.h>
#include "lists.h"
/**
 * find_listint_loop - finds the beginning of the loop.
 *
 * @head: head of the linked list.
 *
 * Return: The address of the node where the loop starts,
 *         or NULL if there is no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;

	slow = head;
	fast = head;
	while (head)
	{
		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
			{
				while (slow)
				{
					slow = slow->next;
					if (slow == head)
						return (slow);
					else if (fast == slow)
					{
						head = head->next;
						break;
					}
				}
			}
		}
		head = head->next;
	}
	return (NULL);
}
