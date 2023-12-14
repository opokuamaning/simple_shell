#include "shell.h"

int main(void)
{
    char *input;

    while (1)
    {
        printf("#cisfun$ ");
        input = custom_getline();

        if (!input)
        {
            printf("\n");
            break;
        }

        execute_command(input);

        free(input);
    }

    return 0;
}

