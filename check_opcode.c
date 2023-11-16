#include "monty.h"

/**
 * check_opcode - checking which opcode is {push, pall, pint, pop}
 *
 * @op: opcode.
 *
 * Return: the function that executes the opcode.
 */
void (*check_opcode(char *op))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"queue", _queue},
		{"stack", _stack},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{NULL, NULL}
	};
	int x;

	for (x = 0; instruct[x].opcode; x++)
	{
		if (_strcmp(instruct[x].opcode, op) == 0)
			break;
	}

	return (instruct[x].f);
}
