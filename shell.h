#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include <sys/types.h>

#define MAX_ALIASES 100

struct Alias {
    char *name;
    char *value;
};

extern struct Alias aliases[MAX_ALIASES];

#define ARG_MAX 1024

void setup_environment(void);
char *get_input(void);
void parse_input(char *input);
void cleanup_memory(void);
int execute_single_command(char *command);
void execute_command(char *input);
void execute_commands_from_file(const char *filename);
void handle_exit(char *status_str);
void handle_env(void);
char *custom_getline(void);
int is_valid_integer(const char *str);
void handle_setenv(char *variable, char *value);
void handle_unsetenv(char *variable);
void change_directory(char *path);
void handle_cd(char *directory);
void handle_alias(int arg_count, char *args[]);
char *replace_variables(char *command);
void tokenize_input(const char *input, char *args[], int *arg_count);

#endif

