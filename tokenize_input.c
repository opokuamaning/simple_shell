#include "shell.h"
/*
 * tokenize_input - Tokenizes a string into individual arguments.
 *
 * @input: The input string to be tokenized.
 * @args: An array to store the resulting tokens.
 * @arg_count: A pointer to an integer to store the number of tokens.
 *
 * Description:
 * This function takes an input string and tokenizes it into individual arguments based on
 * spaces, tabs, and newline characters. It populates the 'args' array with the tokens and
 * updates the 'arg_count' variable accordingly. It also skips comments that begin with
 * a '#' character, treating the rest of the line as a comment and excluding it from
 * the tokenization process.
 *
 * Parameters:
 * - input: The input string to be tokenized.
 * - args: An array to store the resulting tokens.
 * - arg_count: A pointer to an integer to store the number of tokens.
 */
void tokenize_input(const char *input, char *args[], int *arg_count)
{
	char *token;
	char *copy = strdup(input);
	char *saveptr;

	*arg_count = 0;
	token = strtok_r(copy, " \t\n", &saveptr);

	while (token != NULL)
	{
		/* Check if the token starts with "#" to identify comments. */
		if (token[0] == '#')
		{
			break;  /* Ignore the rest of the line if it's a comment. */
		}

		args[(*arg_count)++] = token;
		token = strtok_r(NULL, " \t\n", &saveptr);
	}

	free(copy);
}

