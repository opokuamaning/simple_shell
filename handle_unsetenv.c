#include <shell.h>

/**
 * Handle the setenv built-in command.
 *
 * @param variable The name of the environment variable.
 * @param value The value to set for the environment variable.
 */

void handle_setenv(char *variable, char *value)
{
    if (variable != NULL && is_valid_variable(variable))
    {
        if (setenv(variable, value, 1) == -1)
        {
            perror("Error setting environment variable");
        }
    }
    else
    {
        fprintf(stderr."setenv: Invalid variable name\n");
    }
}
