#include "shell.h"

/**
 * cleanup_memory - Free dynamically allocated memory.
 *
 * Description:
 * This function frees any dynamically allocated memory used
 * in the shell program. It should be called before exiting
 * the program.
 *
 * Return:
 * No explicit return value.
 */
void cleanup_memory(void)
{
	/* Free any dynamically allocated memory here */
	/* For example, free aliases in handle_exit */
	int i;

	for (i = 0; i < MAX_ALIASES; i++)
	{
		free(aliases[i].name);
		free(aliases[i].value);
	}
}
