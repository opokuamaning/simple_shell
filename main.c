#include "shell.h"

/**
 * main - Entry point for the simple_shell.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line;

	while (1)
	{
		write(1, "$ ", 2);
		line = custom_getline();

		if (!line)
		{
			write(1, "\n", 1);
			free(line);
			exit(EXIT_SUCCESS);
		}

		execute_command(line);
		free(line);
	}

	return (0);
}

