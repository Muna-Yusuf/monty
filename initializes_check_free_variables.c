#include "monty.h"

line_t global_v;

/**
 * _free - fress the variables.
 *
 * Return: void.
 */
void _free(void)
{
	free_lists(global_v.head); /*function*/
	free(global_v.buffer);
	fclose(global_v.file_des)
}

/**
 * inital - set variables.
 * @file_des: file descriptor.
 * Return: void.
 */
void inital(FILE *file_des)
{
	global_v.flag = 1;
	global_v.cont = 1;
	global_v.arg = NULL;
	global_v.head = NULL;
	global_v.file_des = file_des;
	global_v.buffer = NULL;
}

/**
 * var_check - function checks if the file could be open or if it's exists.
 * @argc: int.
 * @argv: char.
 * Return: file descriptor.
 */
FILE *var_check(int argc, char *argv[])
{
	FILE *file_des;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_des = fopen(argv[1], "r");
	if (file_des == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (file_des);
}
