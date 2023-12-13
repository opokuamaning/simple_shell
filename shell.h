#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define PROMPT "#cisfun$ "

ssize_t read_line(char *buffer, size_t size);
void execute_command(char *command, char *args[]);

#endif
