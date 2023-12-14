#include "shell.h"

/**
 * trim_whitespace - Trim leading and trailing whitespaces from a string.
 *
 * @str: The string to be trimmed.
 *
 * Return:
 * Returns a newly allocated string with leading and trailing whitespaces removed.
 * The caller is responsible for freeing the returned string.
 */
char *trim_whitespace(const char *str)
{
	const char *end = str + strlen(str) - 1;
	size_t new_len = end - str + 1;
	while (isspace(*str)) {
		str++;
	}

	if (*str == '\0') {
		/* The string is all whitespaces */
		return strdup("");
	}

	while (end > str && isspace(*end)) {
		end--;
	}

	return strndup(str, new_len);
}

