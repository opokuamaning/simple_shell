#include <shell.h>
/**
 * is_valid_integer - Check if a string represents a valid integer.
 *
 * @str: The string to be checked.
 *
 * Description:
 * This function checks if the provided string
 * represents a valid integer.
 * It iterates through each character in the string
 * and verifies if it is a digit.
 * If all characters are digits, the function returns 1 (true),
 * indicating a valid integer;
 * otherwise, it returns 0 (false).
 *
 * Return: 1 if the string is a valid integer, 0 otherwise.
 */
int is_valid_integer(const char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
