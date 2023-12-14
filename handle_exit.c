#include "shell.h"
/**
 * handle_exit - Handle the 'exit' built-in command.
 *
 * @status_str: The string representing the exit status.
 *
 * Description:
 * This function handles the 'exit' command, which terminates the shell.
 * If a status string is provided, it converts it to an integer and uses it
 * as the exit status; otherwise, it defaults to EXIT_SUCCESS.
 */
void handle_exit(char *status_str)
{
	int status;

	if (status_str != NULL)
	{
		status = atoi(status_str);
	}
	else
	{
		status = EXIT_SUCCESS;
	}
	cleanup_memory();
	exit(status);
}
