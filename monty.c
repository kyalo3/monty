#include "monty.h"
#define BUFFERSIZE 1024
#define MAX_LINE_LENGTH 256

/**
 * execute_cmds - executes monty command
 */

void execute_cmds(char *line)
{
	char *args[MAX_LINE_LENGTH] = {NULL}, *token;
	stack_t *stack = NULL;
	int ac, i, j, fintarg;

	opcodeF_t ops[] = {
		{"push", handle_push},
		{"pall", handle_pall},
		{"pint", handle_pint},
		{"pop", handle_pop},
		{"swap", handle_swap},
		{NULL, NULL}};

	if (line != NULL)
	{
		token = strtok(line, " ");
		ac = 0;

		while (token != NULL && ac < MAX_LINE_LENGTH - 1)
		{
			args[ac] = token;
			ac++;
			token = strtok(NULL, " ");
		}
		args[ac] = NULL;

		for (i = 0; args[i]; i++)
		{
			for (j = 0; ops[j].opcode != NULL; j++)
			{
				if (strcmp(args[i], ops[j].opcode) == 0)
				{
					i++;
					ops[j].func(stack, args[i]);
				}
				else
				{
					break;
				}
			}
		}
	}
}
/**
 * read_monty_file - reads a monty file
 * @filename: file to read
 */
void read_monty_file(const char *filename)
{
	ssize_t fd, chars_read, chars_written;
	char buffer[BUFFERSIZE], *line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((chars_read = read(fd, buffer, BUFFERSIZE)) > 0)
	{
		buffer[chars_read] = '\0';
		line = strtok(buffer, "\n");

		while (line != NULL)
		{
			execute_cmd(line);
			line = strtok(NULL, "\n");
		}
	}
	close(fd);
}

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
	read_monty_file(av[1]);
	return (0);
}
