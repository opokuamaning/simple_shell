#include <shell.h>
/**
 * handle_setenv - Handle the 'setenv' built-in command.
 *
 * @variable: The name of the environment variable to set.
 * @value: The value to assign to the environment variable.
 *
 * Description:
 * This function handles the 'setenv' command, which sets or updates
 * the value of an environment variable. It checks if the variable name
 * is valid before attempting to set the environment variable. If successful,
 * the environment variable is set or updated; otherwise, an error message
 * is printed to stderr.
 */
void handle_setenv(char *variable, char *value)
{
	if (variable != NULL && is_valid_variable(variable))
	{
		if (setenv(variable, value, 1) == -1)
		{
			perror("Error setting environment variable");
		}
	}
	else
	{
		fprintf(stderr."setenv: Invalid variable name\n");
	}
}
