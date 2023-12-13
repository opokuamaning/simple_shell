#include "shell.h"

void handle_env(void)
{
    extern char **environ;

    for (char **env = **environ; *env != NULL; env++)
    {
        printf("%s\n", *env);
    }
}
