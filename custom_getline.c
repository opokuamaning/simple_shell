#include <shell.h>
char *custom_getline(void)
{
    static char buffer[ARG_MAX];
    static size_t buffer_index  = 0;
    static ssize_t chars_read = 0;

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
        buffer_index++;
        line_length++;
    }

    if (buffer_index < chars_read && buffer[buffer_index] == '\n')
    {
        buffer_index++;
        line_length++;
    }

    char *result = malloc(line_length + 1);
    
    if (result == NULL)
    {
        perror("Error allocating memory");
        return NULL;
    }

    strncpy(result, line, line_length);
    result[line_length] = '\0';

    return result;
}
