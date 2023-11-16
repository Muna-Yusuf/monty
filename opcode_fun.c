#include "monty.h"

/**
 * _push - function adds nodes.
 * @head: head of the linked list.
 * @line_num: line number.
 * Return: void.
 */
void _push(stack_t **head, unsigned int line_num)
{
	int x, y;

	if (!global_v.arg)
	{
		fprintf(stderr, "L%u: ", line_num);
		fprintf(stderr,"usage: push integer\n");
		_free();
		exit(EXIT_FAILURE);
	}

	for (y = 0; global_v.arg[y] != '\0'; y++)
	{
		if (!isdigit(global_v.arg[y]) && global_v.arg[y] != '-') /*function*/
		{
			fprintf(stderr, "L%u: ", line_num);
			fprintf(stderr, "usage: push integer\n");
			_free();
			exit(EXIT_FAILURE);
		}
	}

	x = atoi(global_v.arg); /*function*/

	if (global_v.flag == 1)
		add_dnodeint(head, x);
	else
		add_dnodeint_end(head, x);
}

/**
 * _pall - functions prints values.
 * @head: head.
 * @line_num: line numbers.
 * Return: void.
 */
void _pall(stack_t **head, unsigned int line_num)
{
	stack_t *x;
	(void)line_num;

	x = *head;

	while (x)
	{
		printf("%d\n", x->n);
		x = x->next;
	}
}

/**
 * _pint - function prints the value at the top.
 * @head: head.
 * @line_num: line number.
 * Return: void.
 */
void _pint(stack_t **head, unsigned int line_num)
{
	(void)line_num;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: ", line_num);
		fprintf(stderr, "can't pint, stack empty\n");
		_free();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}

/**
 * _pop - removes the top element.
 * @head: head.
 * @line_num: line number.
 * Return: void.
 */
void _pop(stack_t **head, unsigned int line_num)
{
	stack_t *x;

	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		_free();
		exit(EXIT_FAILURE);
	}
	x = *head;
	*head = (*head)->next;
	free(x);
}

/**
 * _swap - function swaps the top two elements.
 * @head: head.
 * @line_num: line number.
 * Return: void.
 */
void _swap(stack_t **head, unsigned int line_num)
{
	stack_t *x = NULL;
	int y = 0;

	x = *head;

	for (; x != NULL; x = x->next, y++)
		;

	if (y < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
		_free();
		exit(EXIT_FAILURE);
	}

	x = *head;
	*head = (*head)->next;
	x->next = (*head)->next;
	x->prev = *head;
	(*head)->next = x;
	(*head)->prev = NULL;
}
