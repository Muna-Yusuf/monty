#include "monty.h"

/**
 * add_dnodeint_end - function adds a new node at the end of the list.
 * @head: struct "pointer "
 * @x: int.
 * Return: the address of the new element, or NULL if it failed.
 */
stack_t *add_dnodeint_end(stack_t **head, const int x)
{
	stack_t *tmp;
	stack_t *a;

	if (head == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc failed\n");
		_free();
		exit(EXIT_FAILURE);
	}
	tmp->x = x;
	if (*head == NULL)
	{
		tmp->next = *head;
		tmp->prev = NULL;
		*head = tmp;
		return (*head);
	}
	a = *head;
	while (a->next)
		a = a->next;
	tmp->next = a->next;
	tmp->prev = a;
	a->next = tmp;
	return (a->next);
}

/**
 * add_dnodeint - function adds a new node at the beginning of the list.
 * @head: struct "pointer to current head"
 * @n: int.
 * Return: the address of the new element, or NULL if it failed.
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *tmp;

	if (head == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc failed\n");
		_free();
		exit(EXIT_FAILURE);
	}
	tmp->n = n;
	if (*head == NULL)
	{
		tmp->next = *head;
		tmp->prev = NULL;
		*head = tmp;
		return (*head);
	}
	(*head)->prev = tmp;
	tmp->next = (*head);
	tmp->prev = NULL;
	*head = tmp;
	return (*head);
}
