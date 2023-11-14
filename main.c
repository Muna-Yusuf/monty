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
	ssize_t num_line = 0; /*num*/
	char *line[2] = {NULL, NULL}; /*s*/

	file_des = check_input(argc, argv); /**/
	start_vglo(fd);
	nlines = getline(&vglo.buffer, &size, fd);
	while (nlines != -1)
	{
		lines[0] = _strtoky(vglo.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", vglo.cont);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_vglo();
				exit(EXIT_FAILURE);
			}
			vglo.arg = _strtoky(NULL, " \t\n");
			f(&vglo.head, vglo.cont);
		}
		nlines = getline(&vglo.buffer, &size, fd);
		vglo.cont++;
	}

	free_vglo();

	return (0);
}
