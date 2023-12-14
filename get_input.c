#include "shell.h"
/**
 * get_input - Read a line of input from the user.
 *
 * Description:
 * This function reads a line of input from the user
 * using the getline() function.
 * It allocates memory for the input
 * and handles any errors that may occur during input reading.
 * Return:
 * Returns a pointer to the input string on success,
 * or NULL if an error occurs.
 */
char *get_input(void)
{
	char *input = NULL;
	size_t len = 0;

	if (getline(&input, &len, stdin) == -1)
	{
		perror("Error reading input");
		free(input);
		return (NULL);
	}

	return (input);
}
