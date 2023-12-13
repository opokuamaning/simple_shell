#include "shell.h"

int execute_single_command(char *command)
{
    char *modified_command = replace_variables(command);

    pid_t pid;
    int status;

    int arg_count;
    char *args[ARG_MAX];

    tokenize_input(modified_command, args, &arg_count);

    if (arg_count > 0 && strcmp(args[0], "exit") == 0)
    {
        if (arg_count > 1)
        {
            handle_exit(args[1]);
        }
        else
        {
            handle_exit(NULL);
        }
    }
    else if (arg_count > 0 && strcmp(args[0], "env") == 0)
    {
        handle_env();
    }
    else if (arg_count > 2 && strcmp(args[0], "setenv") == 0)
    {
        handle_setenv(args[1], args[2]);
    }
    else if (arg_count > 1 && strcmp(args[0], "unsetenv") == 0)
    {
        handle_unsetenv(args[1]);
    }
    else if (arg_count > 0 && strcmp(args[0], "cd") == 0)
    {
        handle_cd(arg_count > 1 ? args[1] : NULL);
    }
    else
    {
        pid = fork();

        if (pid == -1)
        {
            perror("Error forking process");
            return (-1);
        }

        if (pid == 0)
        {
            args[arg_count] == NULL;

            if (execvp(args[0], args) == -1)
            {
                perror("Error executing command");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            waitid(pid, &status, 0);

            if (strstr(command, "&&"))
            {
                if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
                {
                    char *next_command = strchr(command, "&") + 2;

                    if (next_command != NULL)
                    {
                        execute_single_command(next_command);
                    }
                }
            }
            else if (strstr(command), "||")
            {
                if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
                {
                    char *next_command = strchr(command, "|") + 2;

                    if (next_command != NULL)
                    {
                        execute_single_command(next_command);
                    }
                }
            }
        }
    }
    free(modified_command);
    return (0);
}
/**
 * Execute commands from a file.
 *
 * @param filename The name of the file containing commands.
 */
void execute_commands_from_file(const char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file)) != -1)
    {
        if (line[read - 1] == '\n')
        {
            line[read - 1] = '\0';
        }

        execute_single_command(line);
    }
    free(line);
    fclose(file);:
}
/**
 * Execute multiple commands separated by ';'.
 *
 * @param input The user input containing one or more commands.
 */
void execute_command(char *input)
{
    char *token =  strtok(input, ";");

    while (token != NULL)
    {
        char *trimmed_command = trim_whitespace(token);
    }

    free(trimmed_command);
    token = strtok(NULL, ";");
}
