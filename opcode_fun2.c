#include "monty.h"

/**
 * _queue - function sets (FIFO).
 * @head: head.
 * @line_num: line number.
 * Return: void.
 */
void _queue(stack_t **head, unsigned int line_num)
{
	(void)head;
	(void)line_num;

	global_v.flag = 0;
}

/**
 * _stack - function sets (LIFO).
 * @head: head.
 * @line_num: line number.
 * Return: void.
 */
void _stack(stack_t **head, unsigned int line_num)
{
	(void)head;
	(void)line_num;

	global_v.flag = 1;
}

/**
 * _add - function adds the top two elements.
 * @head: head.
 * @line_num: line number.
 * Return: void.
 */
void _add(stack_t **head, unsigned int line_num)
{
	stack_t *x = NULL;
	int y = 0;

	x = *head;
	for (; x != NULL; x = x->next, y++)
		;

	if (y < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		_free();
		exit(EXIT_FAILURE);
	}

	x = (*head)->next;
	x->n += (*head)->n;
	_pop(head, line_num);
}

/**
 * _nop - function does nothing.
 * @head: head.
 * @line_num: line number.
 * Return: void.
 */
void _nop(stack_t **head, unsigned int line_num)
{
	(void)head;
	(void)line_num;
}

/**
 * _sub - function subtracts the top element to the second top element.
 * @head: head.
 * @line_num: line number.
 * Return: void.
 */
void _sub(stack_t **head, unsigned int line_num)
{
	stack_t *x = NULL;
	int y = 0;

	x = *head;
	for (; x != NULL; x = x->next, y++)
		;

	if (y < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_num);
		_free();
		exit(EXIT_FAILURE);
	}
	x = (*head)->next;
	x->n -= (*head)->n;
	_pop(head, line_num);
}
