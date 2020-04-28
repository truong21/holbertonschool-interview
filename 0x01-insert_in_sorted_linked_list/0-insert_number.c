#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint - Add node to start of list
 * @head: Pointer to curent head of list
 * @n: Integer to be copied into node
 *
 * Return: Pointer to new node
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}

/**
 * insert_node - Add number into sorted list
 * @head: Pointer to curent head of list
 * @number: Integer to be copied into node
 *
 * Return: Pointer to new node
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node = NULL;
	listint_t *current = NULL;

	if (!head)
		return (NULL);
	
    if (!*head)
	{
		new_node = add_nodeint(head, number);
		return (new_node);
	}

	if (!(*head)->next)
	{
		if ((*head)->n > number)
		{
			new_node = add_nodeint(head, number);
			return (new_node);
		}
		add_nodeint_end(head, number);
	}
	
    current = *head;
	if ((*head)->n > number)
	{
		new_node = add_nodeint(head, number);
		return (new_node);
	}
	while (current->next)
	{
		if (current->next->n > number)
			break;
		current = current->next;
	}
	new_node = malloc(sizeof(listint_t *));
	if (!new_node)
		return (NULL);
	new_node->n = number;
	new_node->next = current->next;
	current->next = new_node;
	return (new_node);
}
