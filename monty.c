#include "monty.h"

char *value = "";
stack_t **stack;

/**
 * read_monty_file - reads a monty file
 * @filename: file to read
 */

void read_monty_file(const char *filename)
{
	int fd;
	ssize_t chars_read;
	char buffer[BUFFERSIZE];
	char *lines[MAX_LINES], *line;
	int line_number = 0, i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((chars_read = read(fd, buffer, BUFFERSIZE)) > 0 &&
		   line_number < MAX_LINES)
	{
		buffer[chars_read] = '\0';
		line = strtok(buffer, "\n");

		while (line != NULL)
		{
			lines[line_number] = strdup(line);
			if (lines[line_number] == NULL)
			{
				close(fd);
				for (i = 0; i < line_number; i++)
				{
					free(lines[i]);
				}
				exit(EXIT_FAILURE);
			}
			line = strtok(NULL, "\n");
			line_number++;
		}
		for (i = 0; lines[i]; i++)
		{
			execute_cmds(lines[i], (i + 1));
		}
	}
	close(fd);
}
/**
 * tokenize_line - breaks line into small tokens
 * @line:line to be tokenized
 * Return: pointer to the args array containing tokens
 */
char **tokenize_line(char *line)
{
	char **args = (char **)malloc((MAX_LINE_LENGTH + 1) * sizeof(char *));
	char *token;
	int ac = 0;

	if (args == NULL)
	{
		return (NULL);
	}
	token = strtok(line, " \t");
	while (token != NULL && ac < MAX_LINE_LENGTH - 1)
	{
		args[ac] = token;
		ac++;
		token = strtok(NULL, " \t");
	}
	args[ac] = NULL;

	return (args);
}

/**
 * execute_cmds - executes monty command
 * @line: line with opcodes
 * @line_number: monty instructions line number
 */

void execute_cmds(char *line, unsigned int line_number)
{
	char *instruction, **args;
	int i = 0, j = 0;
	instruction_t ops[] = {
		{"push", handle_push},
		{"pall", handle_pall},
		{"pop", handle_pop},
		{"pint", handle_pint},
		{"add", handle_add},
		{"swap", handle_swap},
		{NULL, NULL}};

	args = tokenize_line(line);
	while (args[i] != NULL)
	{
		j = 0;
		instruction = args[i];
		value = args[(i + 1)];
		while (ops[j].opcode != NULL)
		{
			if (strcmp(ops[j].opcode, instruction) == 0)
			{
				i += 2;
				ops[j].f(stack, line_number);
				break;
			}
			j++;
		}
		if (ops[j].opcode == NULL)
		{
			dprintf(2, "L%d: unknown instruction %s\n", line_number, instruction);
			exit(EXIT_FAILURE);
		}
	}
}
