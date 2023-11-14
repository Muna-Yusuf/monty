#include "monty.h"

/**
 * main - where the program starts.
 * @argc: int.
 * @argv: char.
 * Return: 0.
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number); /**/
	FILE *file_des;
	size_t size = 256;
	ssize_t num_line = 0;
	char *line[2] = {NULL, NULL};

	file_des = var_check(argc, argv);
	inital(file_des);
	num_line = getline(&vglo.buffer, &size, fd);
	while (num_line != -1)
	{
		line[0] = _strtoky(global_v.buffer, " \t\n");
		if (line[0] && line[0][0] != '#')
		{
			f = get_opcodes(line[0]); /*function*/
			if (!f)
			{
				dprintf(2, "L%u: ", global_v.cont);
				dprintf(2, "unknown instruction %s\n", line[0]);
				_free();
				exit(EXIT_FAILURE);
			}
			global_v.arg = _strtoky(NULL, " \t\n");
			f(&global_v.head, global_v.cont);
		}
		num_line = getline(&global_v.buffer, &size, file_des);
		global_v.cont++;
	}
	_free();
	return (0);
}
