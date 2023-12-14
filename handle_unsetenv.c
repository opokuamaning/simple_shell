#include <shell.h>
/**
 * handle_unsetenv - Handle the 'unsetenv' built-in command.
 *
 * @variable: The name of the environment variable to unset.
 *
 * Description:
 * This function handles the 'unsetenv' command, which removes the specified
 * environment variable. It checks if the variable name is valid before
 * attempting to unset the environment variable. If successful, the environment
 * variable is removed; otherwise, an error message is printed to stderr.
 */
void handle_unsetenv(char *variable)
{
	if (variable != NULL && is_valid_variable(variable))
	{
		if (unsetenv(variable) == -1)
		{
			perror("Error unsetting envrionmanet variable");
		}
	}
	else
	{
		fprintf(stderr, "Unsetenv: Invalid variable name\n");
	}
}
