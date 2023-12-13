#include <shell.h>
/**
 * Check if a string is a valid variable name.
 *
 * @param str The string to check.
 * @return 1 if the string is a valid variable name, 0 otherwise.
 */
int is_valid_integer(const char *str)
{
    while (*str)
    {
        if(!isdigit(*str))
        {
            return (0);
        }
        str++;
    }
    return (1);
}
