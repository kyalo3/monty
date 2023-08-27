#include "monty.h"

char *value = "";
stack_t **stack;
char **args = NULL;
char *line = NULL;

/**
 * read_monty_file - reads a monty file
 * @filename: file to read
 */
void read_monty_file(const char *filename)
{
	FILE *file = fopen(filename, "r");
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 1;

	line = NULL;
	if (file == NULL)
	{
		free_all();
		dprintf(2, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		execute_cmds(line, line_number);
		line_number++;
	}
	free(line);
	fclose(file);
}

/**
 * tokenize_line - breaks line into small tokens
 * @line:line to be tokenized
 */
void tokenize_line(char *line)
{
	char *token;
	int ac = 0, i;

	args = (char **)malloc((MAX_LINE_LENGTH + 1) * sizeof(char *));
	if (args == NULL)
	{
		free_all();
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < MAX_LINE_LENGTH + 1; i++)
	{
		args[i] = NULL;
	}
	token = strtok(line, " \t\n");
	while (token != NULL && ac < MAX_LINE_LENGTH - 1)
	{
		args[ac] = token;
		ac++;
		token = strtok(NULL, " \t\n");
	}
	args[ac] = NULL;
}

/**
 * execute_cmds - executes monty command
 * @line: line with opcodes
 * @line_number: monty instructions line number
 */

void execute_cmds(char *line, unsigned int line_number)
{
	char *instruction;
	int i = 0, j = 0;
	instruction_t ops[] = {
		{"push", handle_push},
		{"pall", handle_pall},
		{"pop", handle_pop},
		{"pint", handle_pint},
		{"add", handle_add},
		{"swap", handle_swap},
		{NULL, NULL}};

	tokenize_line(line);
	while (args[i] != NULL)
	{
		j = 0;
		instruction = args[i];
		value = args[(i + 1)];
		while (ops[j].opcode != NULL)
		{
			if (strcmp(ops[j].opcode, instruction) == 0)
			{
				if (strcmp(ops[j].opcode, "push") == 0)
					i += 2;
				else
					i += 1;
				ops[j].f(stack, line_number);
				break;
			}
			j++;
		}
		i++;
	}
	free(args);
}
