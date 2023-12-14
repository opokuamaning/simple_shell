#include "shell.h"

/**
 * execute_command - Execute a command in a child process.
 *
 * @input: The command to be executed.
 * Return: No return value.
 */
void execute_command(char *input)
{
	char *args[2];
	pid_t pid;
	int status;

	input[strlen(input) - 1] = '\0';  /* Remove the newline character */

	args[0] = input;
	args[1] = NULL;

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execve(args[0], args, NULL) == -1)
		{
			perror("shell");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("shell");
	}
	else
	{
		/* Parent process */
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
		{
			pid = waitpid(pid, &status, WUNTRACED);
		}
	}
}

