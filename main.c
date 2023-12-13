#include "shell.h"
/**
 * main - Entry point for the shell program
 * @argc: The argument count
 * @argv: The argument vector
 * Return: Always 0
 *
 * Description:
 * This function serves as the main entry point for the shell program.
 * It sets up the environment, processes command-line arguments,
 * and either executes commands from a file or enters interactive mode
 * to process user input.
 *
 * Variables to Check (Betty):
 * - Function name (main) should be in lowercase.
 * - Parameter names (argc, argv) are fine; ensure they are lowercase.
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
