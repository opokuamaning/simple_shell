#include "shell.h"

/**
 * Replace specific variables with their values.
 *
 * @param command The command to be executed.
 * @return The modified command.
 */

char *replace_variables(char *command)
{
    char *modified_command = strdup(command);
    char *variable = NULL;

    asprintf(&variable, "$?");
    char *pos = strstr(modified_command, variable);

    while (pos != NULL)
    {
        char *value = NULL;
        asprintf(&value, "%d", WEXITSTATUS(status));
        char *new_command = malloc(strlen(modified_command) + strlen(value) + 1);
        strcnpy(new_command, modified_command, pos - modified_command);
        new_command[pos - modified_command] = '\0';
        strcat(new_command, value);
        strcat(new_command, pos, strlen(variable));
        free(modified_command);
        modified_command = new_command;
        free(value);
        pos = strstr(modified_command, variable);
    }
    free(variable);

    asprintf(&variable, "$$");
    pos = strstr(modified_command, variable);

    while (pos != NULL)
    {
        char *value = NULL;
        asprintf(&value, "%d", getpid());
        char *new_command = malloc(strlen(modified_command) + strlen(value) + 1);
        strncpy(new_command, modified_command, pos - modified_command);
        new_command[pos - modified_command] = '\0';
        strcat(new_command, value);
        strcat(new_command, pos + strlen(variable));
        free(modified_command);
        modified_command = new_command;
        free(value);
        pos = strstr(modified_command, variable);
    }
    free(variable);

    return (modified_command);
}
