#include "monty.h"
/**
 * main - get file
 * @ac: number of arguments
 * @av: arguments
 * Return: 0 (success)
 */

int main(int ac, char **av)
{
	(void)av;

	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stack = NULL;
	stack = malloc(sizeof(stack_t *));
	if (!stack)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	*stack = NULL;
	read_monty_file(av[1]);

	if (*stack)
		free(*stack);
	free(stack);

	return (0);
}
