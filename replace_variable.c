#include "shell.h"
/*
 * main - Entry point for the custom shell program.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array containing the command-line arguments.
 *
 * Description:
 * This main function serves as the entry point for the custom shell program.
 * It performs
 * the following steps:
 * 1. Calls setup_environment() to initialize the shell environment.
 * 2. Checks the number of command-line arguments:
 *    a. If there are two arguments, assumes the second argument
 *    is a script file and
 *       executes commands from the file using
 *       execute_commands_from_file(argv[1]).
 *    b. If there are no or more than two arguments,
 *    enters an interactive mode:
 *       i. Displays a prompt ("$ ").
 *       ii. Reads user input using get_input().
 *       iii. Executes a single command using execute_single_command(input).
 *       iv. Frees the allocated memory for the input.
 *       v. Repeats the interactive loop until the user exits.
 * 3. Calls cleanup_memory() to release any allocated resources.
 *
 * Return:
 * The exit status of the shell program.
 */
char *replace_variables(char *command)
{
	/* Create a duplicate of the original command string for modification. */
	char *modified_command = strdup(command);

	char *variable = NULL;

	int status;

	/* Replace "$?" with the exit status of the last command. */
	asprintf(&variable, "$?");
	char *pos = strstr(modified_command, variable);

	while (pos != NULL)
	{
		/* Convert the exit status to a string. */
		char *value = NULL;

		asprintf(&value, "%d", WEXITSTATUS(status));

		/* Create a new string with the replaced value. */
		char *new_command = malloc(strlen(modified_command) + strlen(value) + strlen(pos) + 1);

		strncpy(new_command, modified_command, pos - modified_command);
		new_command[pos - modified_command] = '\0';
		strcat(new_command, value);
		strcat(new_command, pos + strlen(variable));

		/* Free the memory of the original modified string and update it. */
		free(modified_command);
		modified_command = new_command;

		/* Free the memory of the value string. */
		free(value);

		/* Find the next occurrence of the variable. */
		pos = strstr(modified_command, variable);
	}

	/* Free the memory used for the variable string. */
	free(variable);

	/* Replace "$$" with the process ID. */
	asprintf(&variable, "$$");
	pos = strstr(modified_command, variable);

	while (pos != NULL)
	{
		/* Convert the process ID to a string. */
		char *value = NULL;

		asprintf(&value, "%d", getpid());

		/* Create a new string with the replaced value. */
		char *new_command = malloc(strlen(modified_command) + strlen(value) + strlen(pos) + 1);

		strncpy(new_command, modified_command, pos - modified_command);

		new_command[pos - modified_command] = '\0';
		strcat(new_command, value);
		strcat(new_command, pos + strlen(variable));

		/* Free the memory of the original modified string and update it. */
		free(modified_command);
		modified_command = new_command;

		/* Free the memory of the value string. */
		free(value);

		/* Find the next occurrence of the variable. */
		pos = strstr(modified_command, variable);
	}

	/* Free the memory used for the variable string. */
	free(variable);

	/* Return the final modified command string. */
	return (modified_command);
}
