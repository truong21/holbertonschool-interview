#include "lists.h"
/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: pointer to the head of the linked list
 * Return: 1 if there is a cycle; otherwise 0.
 **/
int check_cycle(listint_t *list)
{
	listint_t *n = list;
	listint_t *m = list;

	while (m && m->next)
	{
		n = n->next;
		m = m->next->next;
		if (n == m)
			return (1);
	}
	return (0);
}
