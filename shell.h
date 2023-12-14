#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 1024

/* Function prototypes */
char *custom_getline(void);
void execute_command(char *input);

#endif /* SHELL_H */

