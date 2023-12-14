#include "shell.h"

/**
 * execute_command - Execute a command.
 * @command: The command to execute.
 *
 * Return: Always 0.
 */
int execute_command(char *command)
{
	pid_t pid;
	int status;
	char *args[2];

	args[0] = command;
	args[1] = NULL;

	pid = fork();

	if (pid == 0)
	{
		/* Child process */
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Error in child process");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		/* Forking error */
		perror("Error forking process");
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process */
		do {
			pid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (0);
}

