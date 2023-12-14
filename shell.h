#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024

/* Function prototypes */
char *custom_getline(void);
int execute_command(char *command);

#endif /* SHELL_H */

