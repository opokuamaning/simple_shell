#include "shell.h"

/**
 * Tokenize the input command into an array of arguments.
 *
 * @param input     The input command.
 * @param args      An array to store the arguments.
 * @param arg_count A variable to store the number of arguments.
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
        if (token[0] == "#")
        {
            break;
        }

        args[(*arg_count)++] = token;
        token = strtok_r(NULL, " \t\n", &saveptr);
    }

    free(copy);
}
