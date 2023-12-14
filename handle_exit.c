#include "shell.h"
static int last_exit_status = 0;

/*
 * get_last_exit_status - Get the last exit status.
 *
 * Description:
 * This function returns the last exit status set by the handle_exit function.
 */
int get_last_exit_status(void)
{
	return last_exit_status;
}
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
		last_exit_status = status;
	}
	else
	{
		status = EXIT_SUCCESS;
	}
	cleanup_memory();
	exit(last_exit_status);
}
