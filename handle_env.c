#include "shell.h"

/*
 * Handle the 'env' builtin command.
 *
 * Description:
 * This function prints the environment variables.
 */
void handle_env(void) {
	extern char **environ;
	char **env;

	for (env = environ; *env != NULL; env++) {
		printf("%s\n", *env);
	}
}

