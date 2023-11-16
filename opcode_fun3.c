#include "monty.h"

/**
 * _div - function divides elements.
 * @head: head.
 * @line_num: line num.
 * Return: void.
 */

void _div(stack_t **head, unsigned int line_num)
{
	stack_t *x = NULL;
	int y = 0;

	x = *head;
	for (; x != NULL; x = x->next, y++)
		;
	if (y < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_num);
		_free();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		_free();
		exit(EXIT_FAILURE);
	}
	x = (*head)->next;
	x->n /= (*head)->n;
	_pop(head, line_num);
}

/**
 * _mul - function divides elements.
 * @head: head.
 * @line_num: line num.
 * Return: void.
 */

void _mul(stack_t **head, unsigned int line_num)
{
	stack_t *x = NULL;
	int y = 0;

	x = *head;
	for (; x != NULL; x = x->next, y++)
		;
	if (y < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_num);
		_free();
		exit(EXIT_FAILURE);
	}
	x = (*head)->next;
	x->n *= (*head)->n;
	_pop(head, line_num);
}

/**
 * _mod - function divides elements.
 * @head: head.
 * @line_num: line num.
 * Return: void.
 */

void _mod(stack_t **head, unsigned int line_num)
{
	stack_t *x = NULL;
	int y = 0;

	x = *head;
	for (; x != NULL; x = x->next, y++)
		;
	if (y < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_num);
		_free();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		_free();
		exit(EXIT_FAILURE);
	}
	x = (*head)->next;
	x->n %= (*head)->n;
	_pop(head, line_num);
}
