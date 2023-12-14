#include "shell.h"

/**
 * custom_getline - Read a line from standard input.
 *
 * Description:
 * This function reads a line from standard input
 * and returns it as a dynamically allocated string.
 * It uses a static buffer to store the input temporarily.
 *
 * Return:
 * If successful, returns a dynamically allocated string
 * containing the read line.
 * If the end of file (EOF) is reached, returns NULL.
 * If there is an error reading input or allocating memory,
 * returns NULL.
 */
char *custom_getline(void)
{
	char *buffer = NULL;
	size_t buffer_size = 0;

	if (getline(&buffer, &buffer_size, stdin) == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}

	return (buffer);
}
