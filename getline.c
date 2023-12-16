#include "shell.h"

/**
 * get_line - reads a line from the standard input into a dynamically allocated buffer
 * @str: pointer to a buffer that will store the user's command
 * Return: number of characters read (including the newline character), or -1 on error
 */
size_t get_line(char **str)
{
	ssize_t i = 0, size = 0, t = 0, t2 = 0, n = 0;
	char buff[1024];

	/* Read until newline or end of input */
	while (t2 == 0 && (i = read(STDIN_FILENO, buff, 1024 - 1)) > 0)
	{
		buff[i] = '\0'; /* Null-terminate buff to use with _strcat */

		/* Check for newline in the input */
		n = 0;
		while (buff[n] != '\0')
		{
			if (buff[n] == '\n')
				t2 = 1;
			n++;
		}

		/* Copy what's read to buff into the get_line's buffer */
		if (t == 0) /* Malloc the first time */
		{
			*str = malloc((size_t)(i + 1)); /* +1 to account for the null terminator */
			if (*str == NULL)
				return -1; /* Error handling for malloc failure */

			*str = _strcpy(*str, buff);
			size = i + 1;
			t = 1;
		}
		else /* Realloc via _strcat with each loop */
		{
			size += i;
			*str = _strcat(*str, buff);
		}
	}

	return (size);
}

