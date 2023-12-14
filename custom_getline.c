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
 *
 * Variables to Check (Betty):
 * - Function name (custom_getline) should be in lowercase.
 * - No specific variable names need to be checked.
 */
char *custom_getline(void)
{
	static char buffer[ARG_MAX] = {0};
	static size_t buffer_index = 0;
	static ssize_t chars_read = 0;

	if (buffer_index == 0)
	{
		memset(buffer, 0, ARG_MAX);
	}

	if (buffer_index >= chars_read || chars_read == 0)
	{
		chars_read = read(STDIN_FILENO, buffer, ARG_MAX);
		buffer_index = 0;

		if (chars_read == 0)
		{
			return (NULL);
		}

		if (chars_read == -1)
		{
			perror("Error reading input");
			return (NULL);
		}
	}

	char *line = &buffer[buffer_index];
	size_t line_length = 0;

	while (buffer_index < chars_read && buffer[buffer_index] != '\n')
	{
		line_length++;
		buffer_index++;
	}

	char *result = malloc(line_length + 1);
	if (result == NULL)
	{
		perror("Error allocating memory");
		return (NULL);
	}

	strncpy(result, line, line_length);
	result[line_length] = '\0';

	buffer_index++; // Move past the newline character

	return result;
}
