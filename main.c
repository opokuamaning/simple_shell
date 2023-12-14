#include "shell.h"
/**
 * main - Entry point for the custom shell program.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array containing the command-line arguments.
 *
 * Description:
 * The main function serves as the entry point for the
 * custom shell program. It performs
 * the following steps:
 * 1. Calls setup_environment() to initialize the shell environment.
 * 2. Checks the number of command-line arguments:
 *    a. If there are two arguments, assumes the second
 *    argument is a script file and
 *       executes commands from the file using
 *       execute_commands_from_file(argv[1]).
 *    b. If there are no or more than two arguments,
 *    enters an interactive mode:
 *       i. Displays a prompt ("$ ").
 *       ii. Reads user input using get_input().
 *       iii. Executes a single command using
 *       execute_single_command(input).
 *       iv. Frees the allocated memory for the input.
 *       v. Repeats the interactive loop until the user exits.
 * 3. Calls cleanup_memory() to release any allocated resources.
 *
 * Return:
 * The exit status of the shell program.
 */
int main(int argc, char *argv[])
{
	char *input;

	setup_environment();

	if (argc == 2)
	{
		execute_commands_from_file(argv[1]);
	}
	else
	{
		while (1)
		{
			printf("$ ");
			input = get_input();
			if (input == NULL)
			{
				break;
			}
			execute_single_command(input);
			free(input);
		}
	}
	cleanup_memory();

	return (0);
}
