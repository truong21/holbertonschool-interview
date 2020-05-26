#include "lists.h"

/**
 * node_index - Get node at index
 * @head: Pointer to head of list
 * @idx: Target node index
 * Return: Node at index idx
 */
listint_t *node_index(listint_t *head, int indx)
{
	listint_t *current = head;

	while (indx)
	{
		indx--;
		current = current->next;
	}
	return (current);
}

/**
 * list_len - Find length of linked list
 * @head: Pointer to head of list
 * Return: Length of list
 */
int list_len(listint_t *head)
{
	int len = 0;
	listint_t *current = head;

	while (current)
	{
		len++;
		current = current->next;
	}
	return (len);
}

/**
 * is_palindrome - Determine if linked list is a palindrome
 * @head: Pointer to address of first node
 *
 * Return: 1 if list is a palindrome, 0 if not
 */
int is_palindrome(listint_t **head)
{
	listint_t *node_a, *node_b;
	int len = list_len(*head);
	int idx;

	if (len > 1)
	{
		for (idx = 0; idx < len; idx++)
		{
			node_a = node_index(*head, idx);
			node_b = node_index(*head, len - idx - 1);

			if (node_a->n != node_b->n)
				return (0);
			if (node_a == node_b || node_a->next == node_b)
				break;
		}
	}
	return (1);
}
