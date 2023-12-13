#include "shell.h"

int main(int argc, char *argv[])
{
    char *input;

    setup_environment();

    if (argc == 2)
    {
        execute_commands_from_file(argv[1]);
    }
    else
    {
        while (1)
        {
            printf("$ ");
            input = get_input();
            if (input == NULL)
            {
                break;
            }
            execute_single_command(input);
            free(input);
        }
    }
    cleanup_memory();

    return (0);
}
