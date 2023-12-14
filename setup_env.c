#include "shell.h"

/**
 * setup_environment -  Setup the shell environment.
 * Return: 0
 */
void setup_environment(void)
{
	/* Initialize any necessary data structures or variables */
	/* For example, you can initialize your aliases array */
	int i;

	for (i = 0; i < MAX_ALIASES; i++) {
		aliases[i].name = NULL;
		aliases[i].value = NULL;
	}
}

