#include "monty.h"

/**
 * _rotl - function divides elements.
 * @head: head.
 * @line_num: line num.
 * Return: void.
 */

void _rotl(stack_t **head, unsigned int line_num)
{
	stack_t *x1 = NULL;
	stack_t *x2 = NULL;
	(void)line_num;

	if (*head == NULL)
	{
		return;
	}
	if ((*head)->next == NULL)
	{
		return;
	}
	x1 = (*head)->next;
	x2 = *head;

	for (; x2->next != NULL; x2 = x2->next)
		;
	x1->prev = NULL;
	x2->next = *head;
	(*head)->next = NULL;
	(*head)->prev = x2;
	*head = x1;
}
