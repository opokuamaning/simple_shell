#include "shell.h"

void handle_exit(char *status_str)
{
    int status;

    if (status_str != NULL && is_val)
    {
        status = atoi(status_str);
    }
    else
    {
        status = EXIT_SUCCESS;
    }
    cleanup_memory();
    exit(status);
}
