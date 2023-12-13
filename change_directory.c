#include "shell.h"

/**
 * change_directory - Change the current working directory and update the
 * PWD environment variable.
 *
 * @path: The path to the directory to change to.
 * Return: No value
 *
 * Description:
 * This function changes the current working directory to the specified path
 * and updates the PWD environment variable accordingly.
 *
 * Variables to Check (Betty):
 * - Function name (change_directory) should be in lowercase.
 * - Parameter name (path) is fine; ensure it's lowercase.
 */
void change_directory(char *path)
{
	char *current_directory = getcwd(NULL, 0);

	if (chdir(path) == 0)
	{
		setenv("PWD", getcwd(NULL, 0), 1);
	}
	else
	{
		perror("cd");
	}

	free(current_directory);
}
/**
 * handle_cd - Handle the 'cd' command, changing to the specified directory.
 *
 * @directory: The directory to change to. If NULL, change to the home
 * directory.
 *
 * Description:
 * This function handles the 'cd' command, changing to the specified directory.
 * If no directory is provided, it changes to the home directory.
 * If the directory is "-", it changes to the previous directory (if set).
 *
 * Return:
 * No explicit return value.
 *
 * Variables to Check (Betty):
 * - Function name (handle_cd) should be in lowercase.
 * - Parameter name (directory) is fine; ensure it's lowercase.
 */
void handle_cd(char *directory)
{
	char *home_dir == get_env("HOME");

	if (directory == NULL)
	{
		change_directory(home_dir);
	}
	else if (strcmp(directory, "-") == 0)
	{
		char *previous_dir = getenv("OLDPWD");

		if  (previous_dir != NULL)
		{
			change_directory(previous_dir);
		}
		else
		{
			fprintf(stderr, "cd: OLDPWD not set\n");
		}
	}
	else
	{
		change_directory(directory);
	}
}
