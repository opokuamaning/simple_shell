#include "shell.h"

/*
 * Handle the 'alias' builtin command.
 *
 * arg_count: Number of arguments.
 * args:      Array of arguments.
 *
 * Description:
 * This function handles the 'alias' builtin command. It can display existing aliases
 * or create new ones. If no arguments are provided, it prints all existing aliases.
 * If arguments are provided, it either updates existing aliases or prints the value of
 * specified aliases.
 *
 * Note: The MAX_ALIASES constant is assumed to be defined in your "shell.h" file.
 */
void handle_alias(int arg_count, char *args[])
{
	int i;
	if (arg_count == 1) {
		for (i = 0; i < MAX_ALIASES && aliases[i].name != NULL; i++) {
			printf("%s='%s'\n", aliases[i].name, aliases[i].value);
		}
	} else {
		for (i = 1; i < arg_count; i++) {
			char *arg = args[i];

			if (strchr(arg, '=') != NULL) {
				char *name = strtok(arg, "=");
				char *value = strtok(NULL, "=");

				if (value != NULL) {
					int j;

					for (j = 0; j < MAX_ALIASES && aliases[j].name != NULL; j++) {
						if (strcmp(aliases[j].name, name) == 0) {
							free(aliases[j].value);
							aliases[j].value = strdup(value);
						}
					}

					if (j < MAX_ALIASES) {
						aliases[j].name = strdup(name);
						aliases[j].value = strdup(value);
					} else {
						fprintf(stderr, "Error: Maximum number of aliases reached.\n");
					}
				}
			}
		}
	}
}
