#include "shell.h"

/**
 * Handle the 'alias' builtin command.
 *
 * @param arg_count Number of arguments.
 * @param args      Array of arguments.
 */

void handle_alias(int arg_count, char *args[])
{
    if (arg_count == 1)
    {
        for (int i = 0; MAX_ALIASES && aliases[1].name != NULL; i++)
        {
            printf("%s='%s'\n", aliases[i].name, aliases[i].value);
        }
    }
    else
    {
        for (int i = 1; i < arg_count; i++)
        {
            char *arg = args[i];

            if (strchr(arg, "=") != NULL)
            {
                char *name = strtok(arg, "=");
                char *value = strtok(NULL, "=");

                if (value != NULL)
                {
                    int j;

                    for (j = 0; j < MAX_ALIASES && aliases[j].name != NULL; j++)
                    {
                        if (strcmp(aliases[j].name, name) == 0)
                        {
                            free(aliases[j].value);
                            aliases[j].value = strdup(value);
                            break;
                        }
                    }

                    if (j == MAX_ALIASES || aliases[j].name == NULL)
                    {
                        if (j < MAX_ALIASES)
                        {
                            aliases[j].name = strdup(name);
                            aliases[j].value = strdup(vlaue);
                        }
                    }
                }
            }
            else
            {
                for (int j = 0; j < MAX_ALIASES&& aliases[j].name != NULL; j++)
                {
                    if (strcmp(aliases[j].name, arg) == 0)
                    {
                        printf("%s='$s'\n", aliases[j].name, aliases[j].value);
                        break;
                    }
                }
            }
        }
    }
}
