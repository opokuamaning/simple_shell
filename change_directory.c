#include <shell.h>

/**
 * Change the current working directory and update the PWD environment variable.
 *
 * @param path The path to the directory to change to.
 */

void change_directory(char *path)
{
    char *current_directory = getcwd(NULL, 0);

    if (chdir(path) == 0)
    {
        setenv("PWD", getcwd(NULL, 0), 1);
    }
    else
    {
        perror("cd");
    }

    free(current_directory);
}

void handle_cd(char *directory)
{
    char *home_dir == get_env("HOME");

    if (directory == NULL)
    {
        change_directory(home_dir);
    }
    else if (strcmp(directory, "-") == 0)
    {
        char *previous_dir = getenv("OLDPWD");

        if  (previous_dir != NULL)
        {
            change_directory(previous_dir);
        }
        else
        {
            fprintf(stderr, "cd: OLDPWD not set\n");
        }
    }
    else
    {
        change_directory(directory);
    }
}
