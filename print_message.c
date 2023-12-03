#include "shell.h"

/**
 * print_message - Print a message to stdout
 * @msg: The message to print
 * Description: This function prints a message to stdout
 */
void print_message(char *msg)
{
	if (msg != NULL)
	{
		printf("%s\n", msg);
	}
}

/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{
	char *message = "Hello Betty!";

	print_message(message);

	return (0);
}
