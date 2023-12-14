#include "shell.h"

/*
 * Replace variables in the given command.
 *
 * @modified_command: The command with variables to be replaced.
 *
 * Description:
 * This function replaces certain variables in the command with their values.
 * Supported variables include "$?" (exit status) and "$$" (process ID).
 *
 * Return:
 * The modified command with variables replaced.
 */
char *replace_variables(char *modified_command)
{
	char *variable = NULL;
	char *pos = NULL;
	char *new_command = NULL;

	/* Replace "$?" with the exit status. */
	asprintf(&variable, "$?");
	pos = strstr(modified_command, variable);

	while (pos != NULL)
	{
		/* Get the exit status as a string. */
		char *value = NULL;
		asprintf(&value, "%d", get_last_exit_status());

		/* Create a new string with the replaced value. */
		new_command = malloc(strlen(modified_command) + strlen(value) + strlen(pos) + 1);

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
	return modified_command;
}

