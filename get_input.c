#include "shell.h"

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
