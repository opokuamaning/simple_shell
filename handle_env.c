#include "shell.h"
/**
 * handle_env- Handles the 'env' builtin command.
 *
 * Return:
 * This function prints the current environment variables.
 */
void handle_env(void)
{
	for (char **env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
}
